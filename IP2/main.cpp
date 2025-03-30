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

        ht.display();
        std::cout << "\n";

        std::cout << "\n";

        std::cout << "Reading key 15: " << ht.read(15) << "\n";
        std::cout << "\n";

        ht.update(15, 200);
        std::cout << "After update:\n";
        std::cout << "\n";
        ht.display();

        std::cout << "\n";
        ht.deleteEntry(15);
        std::cout << "After deletion:\n";
        std::cout << "\n";
        ht.display();
        std::cout << "\n";

        std::cout << HashTable::getCount();
        std::cout << "\n";
        std::cout << "\n";

        HashTable ht2(10);
        ht2.create(5, 500);
        ht2.create(15, 1050);
        ht2.create(25, 2500);

        ht2.display();
        std::cout << "\n";

        std::cout << "Reading key 15: " << ht2.read(15) << "\n";
        std::cout << "\n";

        ht2.update(15, 2000);
        std::cout << "After update:\n";
        std::cout << "\n";
        ht2.display();
        std::cout << "\n";

        std::cout << HashTable::getCount();
        std::cout << "\n";

        ht.~HashTable();
        std::cout << HashTable::getCount();
        std::cout << "\n";
        ht2.~HashTable();
        std::cout << HashTable::getCount();

        HashTable ht3(10);
        ht3 += std::make_pair(5, 50);
        ht3 += std::make_pair(15, 150);
        ht3 += std::make_pair(25, 250);

        ht3.display();
        std::cout << "\n";

        ht3 -= 15;
        std::cout << "After deletion:\n";
        ht3.display();
        std::cout << "\n";

        ht3[std::make_pair(25, 1050)];
        std::cout << "After update:\n";
        ht3.display();
        std::cout << "\n";

        ht3(25);
        std::cout << "Reading key 25: " << ht3(25) << "\n";
        std::cout << "\n";
        ht3.display();
        std::cout << "HashTable contents: " << ht3.toString() << "\n";
        std::cout << "\n";
        !ht3;
        std::cout << "Displaying hash table:\n";
        ht3.display();
        std::cout << "\n";

        ht3.~HashTable();
        std::cout << HashTable::getCount();

        std::cout << "\nTesting deep copy functionality:\n";
        HashTable ht4(5);
        ht4.create(1, 100);
        ht4.create(2, 200);
        ht4.create(3, 300);

        // Test copy constructor
        HashTable ht5 = ht4;
        std::cout << "Original HashTable (ht4): " << ht4.toString() << "\n";
        std::cout << "Copied HashTable (ht5): " << ht5.toString() << "\n";

        // Verify that modifying copy doesn't affect original
        ht5.update(1, 150);
        ht5.deleteEntry(2);
        std::cout << "After modifying ht5:\n";
        std::cout << "Original HashTable (ht4): " << ht4.toString() << "\n";
        std::cout << "Modified HashTable (ht5): " << ht5.toString() << "\n";

        // Test copy assignment operator
        HashTable ht6(5);
        ht6 = ht4;
        std::cout << "Assigned HashTable (ht6): " << ht6.toString() << "\n";

        // Verify that modifying assigned copy doesn't affect original
        ht6.create(4, 400);
        ht6.update(1, 175);
        std::cout << "After modifying ht6:\n";
        std::cout << "Original HashTable (ht4): " << ht4.toString() << "\n";
        std::cout << "Modified HashTable (ht6): " << ht6.toString() << "\n";

        // Test chained assignments
        HashTable ht7(5);
        HashTable ht8(5);
        ht8 = ht7 = ht4;
        std::cout << "Testing chained assignment:\n";
        std::cout << "ht4: " << ht4.toString() << "\n";
        std::cout << "ht7: " << ht7.toString() << "\n";
        std::cout << "ht8: " << ht8.toString() << "\n";

        // Verify object counter
        std::cout << "\nTesting object counter:\n";
        std::cout << "Current count: " << HashTable::getCount() << "\n";
        ht4.~HashTable();
        std::cout << "After destroying ht4: " << HashTable::getCount() << "\n";
        ht5.~HashTable();
        std::cout << "After destroying ht5: " << HashTable::getCount() << "\n";
        ht6.~HashTable();
        std::cout << "After destroying ht6: " << HashTable::getCount() << "\n";  
        ht7.~HashTable();
        ht8.~HashTable();
        std::cout << "Final count: " << HashTable::getCount() << "\n";

    }
    catch (MyHashTableException& e)
    {
        std::cout << "HashTableException: " << e.what() << "\n";
    }
    catch (...)
    {
        std::cout << "An error occurred";
    }

    return 0;
}
