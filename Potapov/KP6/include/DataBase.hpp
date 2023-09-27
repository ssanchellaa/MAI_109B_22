#ifndef DATABASEHPP
#define DATABASEHPP

#include "RowTable.hpp"
#include <iostream>
#include <string>

class DataBase{
private:
    FILE* file = nullptr;
    std::string file_path;

public:
    DataBase() = default;
    DataBase(const std::string&);
    ~DataBase();

    const std::string create_file(const std::string& file_name = "DB_File");
    void add_data(const RowTable& row);
    void print() const;
    void find_max_GPA() const;
    void delete_file();
};

#include "../src/DataBase.cpp"
#endif //DATABASEHPP