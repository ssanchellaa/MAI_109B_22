#ifndef ROWTABLEHPP
#define ROWTABLEHPP

#include <string>

template <typename T>
class Table;

template <typename T>
class RowTable{
    friend class Table<T>;
private:
    T key;
    std::string data;

public:
    RowTable() = default;
    RowTable(const T& key, const std::string& data);
    ~RowTable() = default;

    T& get_key();

    std::string& get_data();

    bool operator<(const RowTable<T>& other) const;
};

#include "../src/RowTable.cpp"
#endif //ROWTABLEHPP