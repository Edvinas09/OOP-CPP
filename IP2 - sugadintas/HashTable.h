/*
This is a header file for Hash table with open addressing linear probing implementation. Created by: Edvinas Bagdonas, 1 course, 4th group student in software engineering 
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <memory> // For std::unique_ptr
#include <vector> // Needed for vector in implementation

namespace HashTableNamespace {

class HashTable {
    private:
    // Forward declaration of Impl class
    class Impl;

    std::unique_ptr<Impl> pImpl; // Pointer to the implementation

public:
    HashTable(int cap);         // Constructor
    ~HashTable();               // Destructor

    HashTable(const HashTable& other); // Copy constructor
    HashTable& operator=(const HashTable& other); // Copy assignment operator

    void create(int key, int value); // Insert a new entry
    int const read(int key); // Read an entry by key
    void update(int key, int newValue); // Update an existing entry
    void deleteEntry(int key); // Delete an entry by key
    void display();  // Display the hash table
    static int const getCount(); // Get the count of HashTable objects

    HashTable& operator+=(const std::pair<int, int>& keyValuePair); // Overload += operator for creating entries
    HashTable& operator-=(int key); // Overload -= operator for deleting entries
    HashTable& operator()(const std::pair<int, int>& keyValuePair); // Overload () operator for updating entries
    HashTable& operator!(); // Overload ! operator for displaying the hash table
    int operator[](int key); // Overload () operator for reading entries

    std::string toString() const; // Convert the hash table to a string representation

};

} // End of namespace

#endif


#ifndef HASHTABLE_ExCEPTION_H
#define HASHTABLE_ExCEPTION_H

#include <stdexcept>
#include <string>

namespace HashTableNamespace {

class MyHashTableException : public std::exception {
    private:
        std::string msg;
    public:
        MyHashTableException(const std::string& message); // Constructor
        const char* what() const noexcept override; // Override the what() method
};
}
#endif