#include "HashTable.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>

using namespace HashTableNamespace;


MyHashTableException::MyHashTableException(const std::string& message) : msg(message) {}

// what() method
const char* MyHashTableException::what() const noexcept {
    return msg.c_str();
}

// Full definition of Impl class
class HashTable::Impl {
private:
    struct Entry {
        int key;
        int value;
        bool occupied;
        bool deleted;
    };

    friend class HashTable;
    static int count;

    std::vector<Entry> table;
    int capacity;
    int size;
    public:
    Impl(int cap) : capacity(cap), size(0) {
        ++count;
        table.resize(capacity, {-1, -1, false, false});
    }

    ~Impl() {
        --count;
    }

    int hashFunction(int key) {
        return key % capacity;
    }
};


int HashTable::Impl::count = 0;

// Rest of the implementation remains the same as in the previous example
HashTable::HashTable(int cap) : pImpl(std::unique_ptr<Impl>(new Impl(cap))) {}

HashTable::~HashTable() = default;



// Copy constructor 
HashTable::HashTable(const HashTable& other) : pImpl(std::make_unique<Impl>(other.pImpl->capacity)) {
    pImpl->size = other.pImpl->size;
    pImpl->table = other.pImpl->table;
}

// Copy assignment operator
HashTable& HashTable::operator=(const HashTable& other) {
    if (this != &other) {
        // Create new implementation with the same capacity
        auto newImpl = std::make_unique<Impl>(other.pImpl->capacity);
        newImpl->size = other.pImpl->size;
        newImpl->table = other.pImpl->table;
        // Swap the new implementation with the current one
        pImpl = std::move(newImpl);
    }
    return *this;
}



// Static method to get count
int const HashTable::getCount() {
    return Impl::count;
}

// Update an existing entry
void HashTable::update(int key, int newValue) {
    int index = pImpl->hashFunction(key);
    int originalIndex = index;

    while (pImpl->table[index].occupied) {
        if (pImpl->table[index].key == key && !pImpl->table[index].deleted) {
            pImpl->table[index].value = newValue+1;
            return;
        }
        index = (index + 1) % pImpl->capacity;
        if (index == originalIndex) break;
    }
    throw MyHashTableException("Key not found for update!");
}

// Insert a new entry
void HashTable::create(int key, int value) {
    int index = pImpl->hashFunction(key);
    int originalIndex = index;

    while (pImpl->table[index].occupied && !pImpl->table[index].deleted && pImpl->table[index].key != key) {
        index = (index + 1) % pImpl->capacity; // Linear probing
        if (index == originalIndex) {
            throw MyHashTableException("Hash table is full!");
        }
    }

    if (!pImpl->table[index].occupied || pImpl->table[index].deleted) {
        pImpl->table[index] = {key, value, true, false}; // Insert the new entry
        pImpl->size++;
    } else {
        update(key, value); // If key already exists, update the value
    }
}

// Read an entry by key
int const HashTable::read(int key) {
    int index = pImpl->hashFunction(key);
    int originalIndex = index;

    while (pImpl->table[index].occupied) {
        if (pImpl->table[index].key == key && !pImpl->table[index].deleted) {
            return pImpl->table[index].value;
        }
        index = (index + 1) % pImpl->capacity;
        if (index == originalIndex) break;
    }
    return -1; // Not found
}

// Delete an entry by key
void HashTable::deleteEntry(int key) {
    int index = pImpl->hashFunction(key);
    int originalIndex = index;

    while (pImpl->table[index].occupied) {
        if (pImpl->table[index].key == key && !pImpl->table[index].deleted) {
            pImpl->table[index].deleted = true;
            pImpl->size--;
            return;
        }
        index = (index + 1) % pImpl->capacity;
        if (index == originalIndex) break;
    }
    throw MyHashTableException("Key not found!");
}

// Display the hash table
void HashTable::display() {
    for (int i = 0; i < pImpl->capacity; ++i) {
        if (pImpl->table[i].occupied && !pImpl->table[i].deleted) {
            std::cout << "Index " << i << ": (" << pImpl->table[i].key << ", " << pImpl->table[i].value << ")\n";
        } else {
            std::cout << "Index " << i << ": EMPTY\n";
        }
    }
    std::cout << "\n";
}

HashTable& HashTable::operator+=(const std::pair<int, int>& keyValuePair) {
    int key = keyValuePair.first;
    int value = keyValuePair.second;
    create(key, value);
    return *this;
}

HashTable& HashTable::operator-=(int key) {
    deleteEntry(key);
    return *this;
}

HashTable& HashTable::operator()(const std::pair<int, int>& keyValuePair) {

    int key = keyValuePair.first;
    int value = keyValuePair.second;
    update(key, value);
    return *this;
}

HashTable& HashTable::operator!() {
    for (int i = 0; i < pImpl->capacity; ++i) {
        pImpl->table[i].occupied = false; // Mark the entry as unoccupied
        pImpl->table[i].deleted = false;  // Reset the deleted flag
    }
    pImpl->size = 0; // Reset the size of the hash table
    return *this;    // Return the current object to allow chaining
}


int HashTable::operator[](int key) {
    return read(key); 
}


std::string HashTable::toString() const {
    std::string result;
    for (int i = 0; i < pImpl->capacity; ++i) {
        if (pImpl->table[i].occupied && !pImpl->table[i].deleted) {
            if (!result.empty()) {
                result += ", "; // Add a comma separator for multiple entries
            }
            result += "(" + std::to_string(pImpl->table[i].key) + ": " + std::to_string(pImpl->table[i].value) + ")";
        }
    }
    return result.empty() ? "EMPTY" : result; // Return "EMPTY" if no entries exist
}


