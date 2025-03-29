#include <iostream>
#include <vector>
#include "HashTable.h"

using namespace HashTableNamespace;

int main() {
    try
    {
        HashTable ht(5);
        ht.create(5, 50);
        ht.create(15, 150);
        ht.create(25, 250);

        ht.display("test.txt");


        std::cout<<"\n";
    
        std::cout << "Reading key 15: " << ht.read(15) << "\n";
        std::cout<<"\n";
        
        ht.update(15, 200);
        std::cout << "After update:\n";
        std::cout<<"\n";
        ht.display("test.txt");
    
        std::cout<<"\n";
        ht.deleteEntry(15);
        std::cout << "After deletion:\n";
        std::cout<<"\n";
        ht.display("test.txt");
        std::cout<<"\n";
    
        std::cout<<HashTable::getCount();
        std::cout<<"\n";
        std::cout<<"\n";
    
        HashTable ht2(10);
        ht2.create(5, 500);
        ht2.create(15, 1050);
        ht2.create(25, 2500);
    
        ht2.display("test.txt");
        std::cout<<"\n";
    
        std::cout << "Reading key 15: " << ht2.read(15) << "\n";
        std::cout<<"\n";
        
        ht2.update(15, 2000);
        std::cout << "After update:\n";
        std::cout<<"\n";
        ht2.display("test.txt");
        std::cout<<"\n";
    
        std::cout<<HashTable::getCount();
        std::cout<<"\n";
    
        ht.~HashTable();
        std::cout<<HashTable::getCount();
        std::cout<<"\n";
        ht2.~HashTable();
        std::cout<<HashTable::getCount();    
    }
    catch(MyHashTableException& e)
    {
        std::cout << "HashTableException: " << e.what() << "\n";
    }
    catch(...)
    {
        std::cout<<"An error occured";
    }

    return 0;
}
