#include <iostream>
#include "../include/Table.hpp"

int main() {
    Table table;

    table.addEntry(25);
    table.addEntry(10);
    table.addEntry(15);
    table.addEntry(15);
    table.addEntry(1);
    table.addEntry(12);
    table.addEntry(241);
    table.addEntry(13);
    table.addEntry(32);

    std::cout << "Source table: " << std::endl;
    std::cout << table << std::endl;

 
    table.quickSort(0, table.entries.size() - 1);

    std::cout << "Sorted table: " << std::endl;
    std::cout << table << std::endl;

    int searchKey = 1;
    int foundIndex = table.searchByKey(searchKey);

    if (foundIndex != -1) {
        std::cout << "Element with key " << searchKey << " found at position " << foundIndex << std::endl;
    } else {
        std::cout << "Element with key " << searchKey << " not founded" << std::endl;
    }

    return 0;
}
