#include "../include/RowTable.hpp"
#include <iostream>
#include <iomanip>

RowTable::RowTable(
                const std::string& surname_and_initials,
                const std::string& sex,
                const uint64_t group_number,
                const uint16_t computer_science_mark,
                const uint16_t programming_practice_mark,
                const uint16_t linear_algebra_mark,
                const uint16_t math_analysis_mark,
                const uint16_t english_mark,
                const uint16_t philosophy_mark
                ): surname_and_initials(surname_and_initials), sex(sex), group_number(group_number), computer_science_mark(computer_science_mark),
                   programming_practice_mark(programming_practice_mark), linear_algebra_mark(linear_algebra_mark),
                   math_analysis_mark(math_analysis_mark), english_mark(english_mark), philosophy_mark(philosophy_mark){}

double RowTable::get_GPA() const{
    return (computer_science_mark + programming_practice_mark + linear_algebra_mark + math_analysis_mark + english_mark + philosophy_mark) / 6;
}

void RowTable::print() const{
    std::cout << "| " << std::setw(14) << std::left << surname_and_initials << "| " << std::setw(6) << std::left << sex << "| " <<
            std::setw(13) << std::left << group_number << "| " << std::setw(17) << std::left << computer_science_mark << "| " << 
            std::setw(21) << std::left << programming_practice_mark << "| " << std::setw(15) << std::left << linear_algebra_mark << "| " <<
            std::setw(14) << std::left << math_analysis_mark << "| " << std::setw(8) << std::left << english_mark << "| " <<
            std::setw(11) << std::left << philosophy_mark << "|\n"; 
}