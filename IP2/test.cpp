#include <iostream>
#include <vector>
#include "HashTable.h"
#include "cassert"


int main() {
    try
    {
        HashTableNamespace::HashTable ht(10);
        ht.create(5, 50);
        ht.create(15, 150);
        ht.create(25, 250);
        ht.create(35, 350);
        ht.create(45, 450);
    
        HashTableNamespace::HashTable ht2(10);
        ht2.create(5, 50);
        
    
        assert(ht.read(15) == 150);
        ht.create(15, 200);
        assert(ht.read(15) == 200);
        ht.deleteEntry(15);
        assert(ht.read(15) == -1);
        ht.update(25, 200);
        assert(ht.read(25) == 200);
        ht.deleteEntry(45);
        assert(ht.read(45) == -1);
    
        assert(ht2.read(5) == 50);
        ht2.update(5, 100);
        assert(ht2.read(5) == 100);
        ht2.create(10, 100);
        assert(ht2.read(10) == 100);
    
    
        ht.~HashTable();
        assert(HashTableNamespace::HashTable::getCount() == 1);
        ht2.~HashTable();
        assert(HashTableNamespace::HashTable::getCount() == 0);
    }
    catch(...)
    {
        std::cout << "An exception occurred\n";
    }
    
    return 0;
}