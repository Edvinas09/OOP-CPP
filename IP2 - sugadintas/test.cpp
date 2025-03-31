#include <iostream>
#include <vector>
#include <stdexcept> // For std::runtime_error
#include "HashTable.h"
#include "cassert"

int main() {
    try {
        // basic functionality tests
        {
            HashTableNamespace::HashTable ht(10);
            ht.create(5, 50);
            ht.create(15, 150);
            ht.create(25, 250);
            ht.create(35, 350);
            ht.create(45, 450);

            if (ht.read(15) != 150) throw std::runtime_error("ht.read(15) != 150");
            ht.deleteEntry(15);
            if (ht.read(15) != -1) throw std::runtime_error("ht.read(15) != -1 after deletion");
            ht.deleteEntry(45);
            if (ht.read(45) != -1) throw std::runtime_error("ht.read(45) != -1 after deletion");

            std::cout << "Crud tests passed\n";
        }

        {
            HashTableNamespace::HashTable ht2(10);
            ht2.create(5, 50);
            if (ht2.read(5) != 50) throw std::runtime_error("ht2.read(5) != 50");
            ht2.update(5, 100);
            if (ht2.read(5) != 100) throw std::runtime_error("ht2.read(5) != 100");
            ht2.create(10, 100);
            if (ht2.read(10) != 100) throw std::runtime_error("ht2.read(10) != 100");

            if (HashTableNamespace::HashTable::getCount() != 1) throw std::runtime_error("HashTable::getCount() != 1");
            std::cout << "Crud tests passed\n";
        }

        if (HashTableNamespace::HashTable::getCount() != 0) throw std::runtime_error("HashTable::getCount() != 0");

        // operator overloads
        {
            HashTableNamespace::HashTable ht3(5);

            ht3.create(1, 10);
            ht3.create(2, 20);
            ht3.create(3, 30);

            ht3 += std::make_pair(4, 40);
            if (ht3.read(4) != 40) throw std::runtime_error("ht3.read(4) != 40");

            ht3 -= 4;
            if (ht3.read(4) != -1) throw std::runtime_error("ht3.read(4) != -1");

            ht3(std::make_pair(1, 15));
            if (ht3.read(1) != 15) throw std::runtime_error("ht3.read(1) != 15");

            !ht3;
            if (ht3.read(1) != -1) throw std::runtime_error("ht3.read(1) != -1");
            if (ht3.read(2) != -1) throw std::runtime_error("ht3.read(2) != -1");

            if (HashTableNamespace::HashTable::getCount() != 1) throw std::runtime_error("HashTable::getCount() != 1");
            std::cout << "Operator tests passed\n";
        }

        if (HashTableNamespace::HashTable::getCount() != 0) throw std::runtime_error("HashTable::getCount() != 0");

        // copy constructor and assignment operator
        HashTableNamespace::HashTable ht1(5);
        ht1.create(1, 100);
        ht1.create(2, 200);

        HashTableNamespace::HashTable ht2 = ht1;
        if (ht2.read(1) != 100) throw std::runtime_error("ht2.read(1) != 100");
        if (ht2.read(2) != 200) throw std::runtime_error("ht2.read(2) != 200");

        ht2.update(1, 150);
        if (ht1.read(1) != 100) throw std::runtime_error("ht1.read(1) != 100");
        if (ht2.read(1) != 150) throw std::runtime_error("ht2.read(1) != 150");

        HashTableNamespace::HashTable ht4(5);
        ht4 = ht1;
        if (ht4.read(1) != 100) throw std::runtime_error("ht4.read(1) != 100");
        if (ht4.read(2) != 200) throw std::runtime_error("ht4.read(2) != 200");

        ht4.deleteEntry(2);
        if (ht1.read(2) != 200) throw std::runtime_error("ht1.read(2) != 200");
        if (ht4.read(2) != -1) throw std::runtime_error("ht4.read(2) != -1");
        std::cout << "Deep Copy tests passed\n";
    } catch (const std::exception& e) {
        std::cout << "Test failed: " << e.what() << '\n';
    } catch (...) {
        std::cout << "An unknown exception occurred\n";
    }

    return 0;
}