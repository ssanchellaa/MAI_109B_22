#ifndef APPLICANT_HPP_INCLUDED
#define APPLICANT_HPP_INCLUDED

#include <string>

class Applicant
{
    std::string surname = "";
    std::string initials = "";
    char gender = ' '; // 'M' for male, 'F' for female
    int schoolNumber = 0;
    bool hasMedal = false;
    double mathScore = 0.0;
    double physicsScore = 0.0;
    double chemistryScore = 0.0;
    double essayScore = 0.0;
    bool essayPass = false;

public:
    Applicant() = default;
    ~Applicant() = default;
    Applicant(const std::string &_surname, const std::string &_initials, char _gender, int _schoolNumber, bool _hasMedal,
              double _mathScore, double _physicsScore, double _chemistryScore, double _essayScore, bool _essayPass);
    void print() const;
};

#endif // APPLICANT_HPP_INCLUDED


