#include <iostream>
#include <vector>
#include "HashTable.h"
#include "cassert"


int main() {
    try
    {
        // basic functionality tests
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

        // operator overloads
        HashTableNamespace::HashTable ht3(5);
        ht3.create(1, 10);
        ht3.create(2, 20);
        ht3.create(3, 30);

        ht3 += std::make_pair(4, 40);
        assert(ht3.read(4) == 40);

        ht3 -= 4;
        assert(ht3.read(4) == -1); 

        ht3[std::make_pair(1, 15)];
        assert(ht3.read(1) == 15);

        !ht3;
        assert(ht3.read(1) == -1);
        assert(ht3.read(2) == -1);


        assert(HashTableNamespace::HashTable::getCount() == 1); 
        ht3.~HashTable();
        assert(HashTableNamespace::HashTable::getCount() == 0); 

        //copy constructor and assignment operator
        HashTableNamespace::HashTable ht1(5);
        ht1.create(1, 100);
        ht1.create(2, 200);

        HashTableNamespace::HashTable ht2 = ht1; 
        assert(ht2.read(1) == 100);
        assert(ht2.read(2) == 200);

        ht2.update(1, 150);
        assert(ht1.read(1) == 100); 
        assert(ht2.read(1) == 150);

        HashTableNamespace::HashTable ht3(5);
        ht3 = ht1; 
        assert(ht3.read(1) == 100);
        assert(ht3.read(2) == 200);

        ht3.deleteEntry(2);
        assert(ht1.read(2) == 200);
        assert(ht3.read(2) == -1);
    }
    catch(...)
    {
        std::cout << "An exception occurred\n";
    }
    
    return 0;
}