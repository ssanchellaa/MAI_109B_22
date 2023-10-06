#include "../include/Row.hpp"
#include <iomanip>
#include <iostream>

void Row::print() {
    std::cout
            << std::setw(20) << std::left << surname << "\t|\t"
            << std::setw(8) << std::left << initials << "\t|\t"
            << std::setw(8) << std::left << gender << "\t|\t"
            << std::setw(15) << std::left << school_number << "\t|\t"
            << std::setw(10) << std::left << has_medal << "\t|\t"
            << std::setw(6) << std::left << exam1 << "\t|\t"
            << std::setw(6) << std::left << exam2 << "\t|\t"
            << std::setw(6) << std::left << exam3 << "\t|\t"
            << std::setw(15) << std::left << passed_writing << std::endl;
}

Row::Row(const std::string &surname,
         const std::string &initials,
         const char &gender,
         const unsigned int &school_number,
         const bool &has_medal,
         const unsigned int &exam1,
         const unsigned int &exam2,
         const unsigned int &exam3,
         const bool &passed_writing) : surname(surname), initials(initials), gender(gender),
                                       school_number(school_number), has_medal(has_medal),
                                       exam1(exam1), exam2(exam2), exam3(exam3),
                                       passed_writing(passed_writing) {}

std::ostream &operator<<(std::ostream &out, const Row &applicant) {
    out.write(applicant.surname.c_str(), applicant.surname.length() + 1);
    out.write(applicant.initials.c_str(), applicant.initials.length() + 1);
    out.write((char *) &applicant.gender, sizeof(applicant.gender));
    out.write((char *) &applicant.school_number, sizeof(applicant.school_number));
    out.write((char *) &applicant.has_medal, sizeof(applicant.has_medal));
    out.write((char *) &applicant.exam1, sizeof(applicant.exam1));
    out.write((char *) &applicant.exam2, sizeof(applicant.exam2));
    out.write((char *) &applicant.exam3, sizeof(applicant.exam3));
    out.write((char *) &applicant.passed_writing, sizeof(applicant.passed_writing));

    return out;
}

std::istream &operator>>(std::istream &in, Row &applicant) {
    getline(in, applicant.surname, '\0');
    getline(in, applicant.initials, '\0');
    in.read((char *) &applicant.gender, sizeof(applicant.gender));
    in.read((char *) &applicant.school_number, sizeof(applicant.school_number));
    in.read((char *) &applicant.has_medal, sizeof(applicant.has_medal));
    in.read((char *) &applicant.exam1, sizeof(applicant.exam1));
    in.read((char *) &applicant.exam2, sizeof(applicant.exam2));
    in.read((char *) &applicant.exam3, sizeof(applicant.exam3));
    in.read((char *) &applicant.passed_writing, sizeof(applicant.passed_writing));

    return in;
}
