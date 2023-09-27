#ifndef DB_HPP_INCLUDED
#define DB_HPP_INCLUDED

#include <string>
#include <vector>
#include "applicant.hpp"

class ApplicantDB
{
    FILE *file;
    std::string path_to_file;

public:
    ApplicantDB() = default;
    ApplicantDB(const std::string &db_name);
    ~ApplicantDB();
    std::string createDB(const std::string &db_name = "ApplicantDB");
    void deleteDB();
    void addApplicant(const Applicant &new_applicant);
    void print() const;
    void findFemaleApplicantsWithSameScoresAndFailThreshold(double passThreshold) const;
};

#endif // DB_HPP_INCLUDED
