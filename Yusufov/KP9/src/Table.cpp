#include "../include/Table.hpp"
#include <stack>

void Table::addEntry(int key) {
    entries.push_back(TableEntry(key));
}

void Table::quickSort(int low, int high) {
    std::stack<int> stack;

    stack.push(low);
    stack.push(high);

    while (!stack.empty()) {
        high = stack.top();
        stack.pop();
        low = stack.top();
        stack.pop();

        int pivotIdx = partition(low, high);

        if (pivotIdx - 1 > low) {
            stack.push(low);
            stack.push(pivotIdx - 1);
        }

        if (pivotIdx + 1 < high) {
            stack.push(pivotIdx + 1);
            stack.push(high);
        }
    }
}

int Table::searchByKey(int key) const {
    for (size_t i = 0; i < entries.size(); i++) {
        if (entries[i].key == key) {
            return i; 
        }
    }
    return -1;
}

std::ostream& operator<<(std::ostream& os, const Table& table) {
    for (const auto &entry : table.entries) {
        os << entry.key << " ";
    }
    return os;
}

int Table::partition(int low, int high) {
    int pivot = entries[high].key;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (entries[j].key < pivot) {
            i++;
            std::swap(entries[i], entries[j]);
        }
    }
    std::swap(entries[i + 1], entries[high]);
    return (i + 1);
}
