#include "../include/applicant.hpp"
#include <iostream>
#include <iomanip>

Applicant::Applicant(const std::string &_surname, const std::string &_initials, char _gender, int _schoolNumber, bool _hasMedal,
                     double _mathScore, double _physicsScore, double _chemistryScore, double _essayScore, bool _essayPass)
    : surname(_surname), initials(_initials), gender(_gender), schoolNumber(_schoolNumber), hasMedal(_hasMedal),
      mathScore(_mathScore), physicsScore(_physicsScore), chemistryScore(_chemistryScore), essayScore(_essayScore), essayPass(_essayPass) {}

void Applicant::print() const
{
    std::cout << "| " << std::setw(10) << std::left << surname << " | " << std::setw(8) << std::left << initials << " | " << std::setw(5) << std::left << gender << " | "
              << std::setw(13) << std::left << schoolNumber << " | " << std::setw(8) << std::left << (hasMedal ? "Yes" : "No") << " | " << std::setw(9) << std::left << mathScore << " | "
              << std::setw(12) << std::left << physicsScore << " | " << std::setw(13) << std::left << chemistryScore << " | " << std::setw(10) << std::left << essayScore << " | "
              << std::setw(9) << std::left << (essayPass ? "Yes" : "No") << " |" << std::endl;
}
