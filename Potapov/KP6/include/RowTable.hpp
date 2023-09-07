#ifndef ROWTABLEHPP
#define ROWTABLEHPP

#include <iostream>
#include <string>

class DataBase;

class RowTable{
    friend class DataBase;
private:
    std::string surname_and_initials;
    std::string sex;
    uint64_t group_number;
    uint16_t computer_science_mark;
    uint16_t programming_practice_mark;
    uint16_t linear_algebra_mark;
    uint16_t math_analysis_mark;
    uint16_t english_mark;
    uint16_t philosophy_mark;

public:
    RowTable() = default;
    RowTable(
            const std::string&,
            const std::string&,
            const uint64_t,
            const uint16_t,
            const uint16_t,
            const uint16_t,
            const uint16_t,
            const uint16_t,
            const uint16_t
            );
    ~RowTable() = default;

    double get_GPA() const;
    void print() const;
};

#include "../src/RowTable.cpp"
#endif //ROWTABLEHPP