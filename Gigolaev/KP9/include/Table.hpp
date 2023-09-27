#pragma once
#include <iostream>
#include "../../KP7/include/Vector.hpp"
class Table
{
    private:
        Vector<std::pair<int32_t, std::string>> entries;
    public:
        Table() = default;
        ~Table() = default;
        bool AddEntry(std::pair<int32_t, std::string> entry);
        void TournamentSort();
        void Swap(int32_t firstInd, int32_t secondInd);
        std::pair<int32_t, std::string> BinarySearch(int32_t key) const;
        friend std::ostream& operator<<(std::ostream& os, Table& table);
};

#include "../src/Table.cpp"