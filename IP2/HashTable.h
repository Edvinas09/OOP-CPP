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

    // Ensure this is declared BEFORE any methods that use it
    std::unique_ptr<Impl> pImpl; // Pointer to the implementation

public:
    HashTable(int cap);         // Constructor
    ~HashTable();               // Destructor

    void create(int key, int value);
    int const read(int key);
    void update(int key, int newValue);
    void deleteEntry(int key);
    void display(std::string filename);
    static int const getCount();

    HashTable& operator+=(const std::pair<int, int>& keyValuePair); // Overload += operator for creating entries
    HashTable& operator-=(int key); // Overload -= operator for deleting entries
    HashTable& operator[](const std::pair<int, int>& keyValuePair); // Overload -= operator for deleting entries
    HashTable& operator!(); // Overload ! operator for displaying the hash table
    HashTable& operator()(int key); // Overload () operator for reading entries



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