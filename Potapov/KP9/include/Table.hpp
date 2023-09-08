#ifndef TABLEHPP
#define TABLEHPP

#include "../../KP7/include/Vector.hpp"
#include "RowTable.hpp"
#include <iostream>

template <typename T>
class Table{
private:
    Vector<RowTable<T>> rows;

public:
    Table() = default;
    ~Table() = default;

    Vector<RowTable<T>>& get_rows();

    void insert(const T& key, const std::string& data);

    RowTable<T>& search(const T& key);

    void swap(size_t index1, size_t index2);
    void sort();
    void print() const;
};

#include "../src/Table.cpp"
#endif //TABLEHPP