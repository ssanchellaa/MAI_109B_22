#ifndef TABLE_HPP
#define TABLE_HPP

#include <vector>
#include "TableEntry.hpp"

class Table {
public:
    std::vector<TableEntry> entries;

    void printTable() const;
    void mergeSort(int left, int right);
    void mergeSortParallel(int left, int right);
    bool binarySearch(int integerKey, char letterKey) const;
    void getResultsNotEmpty(int integerKey, char letterKey) const;
};

#endif 