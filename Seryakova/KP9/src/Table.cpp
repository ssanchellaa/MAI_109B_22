#include "Table.hpp"
#include <iostream>
#include <thread>

void Table::printTable() const {
    for (const TableEntry& entry : entries) {
        std::cout << "Ключ: " << entry.integerKey << entry.letterKey << ", Запись: " << entry.text << std::endl;
    }
    std::cout << std::endl;
}

void Table::mergeSort(int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;
    mergeSort(left, mid);
    mergeSort(mid + 1, right);

    std::vector<TableEntry> temp(right - left + 1);
    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right) {
        if (entries[i].integerKey < entries[j].integerKey ||
            (entries[i].integerKey == entries[j].integerKey && entries[i].letterKey < entries[j].letterKey)) {
            temp[k] = entries[i];
            i++;
        } else {
            temp[k] = entries[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = entries[i];
        i++;
        k++;
    }

    while (j <= right) {
        temp[k] = entries[j];
        j++;
        k++;
    }

    for (int m = 0; m < k; m++) {
        entries[left + m] = temp[m];
    }
}

void Table::mergeSortParallel(int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;
    std::thread t1(&Table::mergeSort, this, left, mid);
    std::thread t2(&Table::mergeSort, this, mid + 1, right);

    t1.join();
    t2.join();

    std::vector<TableEntry> temp(right - left + 1);
    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right) {
        if (entries[i].integerKey < entries[j].integerKey ||
            (entries[i].integerKey == entries[j].integerKey && entries[i].letterKey < entries[j].letterKey)) {
            temp[k] = entries[i];
            i++;
        } else {
            temp[k] = entries[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = entries[i];
        i++;
        k++;
    }

    while (j <= right) {
        temp[k] = entries[j];
        j++;
        k++;
    }

    for (int m = 0; m < k; m++) {
        entries[left + m] = temp[m];
    }
}

bool Table::binarySearch(int integerKey, char letterKey) const {
    int left = 0;
    int right = entries.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (entries[mid].integerKey == integerKey && entries[mid].letterKey == letterKey) {
            return true;
        }

        if (entries[mid].integerKey < integerKey ||
            (entries[mid].integerKey == integerKey && entries[mid].letterKey < letterKey)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}

void Table::getResultsNotEmpty(int integerKey, char letterKey) const {
    int left = 0;
    int right = entries.size() - 1;
    std::cout << "Результат:";
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (entries[mid].integerKey == integerKey && entries[mid].letterKey == letterKey) {
            std::cout << entries[mid].text << " ";
            right = mid;
        }

        if (entries[mid].integerKey < integerKey ||
            (entries[mid].integerKey == integerKey && entries[mid].letterKey < letterKey)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    std::cout << std::endl;
}