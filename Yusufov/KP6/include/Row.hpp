#ifndef ROW_HPP_INCLUDED
#define ROW_HPP_INCLUDED

#include <string>

class Row {
private:

    std::string surname;
    std::string initials;
    char gender;
    unsigned int school_number;
    bool has_medal;
    unsigned int exam1;
    unsigned int exam2;
    unsigned int exam3;
    bool passed_writing;

public:

    Row() = default;
    Row(
            const std::string &surname,
            const std::string &initials,
            const char &gender,
            const unsigned int &school_number,
            const bool &has_medal,
            const unsigned int &exam1,
            const unsigned int &exam2,
            const unsigned int &exam3,
            const bool &passed_writing
    );

    void print();

    friend std::ostream& operator<<(std::ostream& out, const Row& applicant);
    friend std::istream& operator>>(std::istream& in, Row& applicant);

    friend class Database;
};


#include "../src/Row.cpp"

#endif
