#include "../include/DB.hpp"
#include <stdexcept>
#include <iostream>
#include <dir.h>

ApplicantDB::ApplicantDB(const std::string &db_name)
{
    path_to_file = createDB(db_name);
    file = fopen(path_to_file.c_str(), "wb+");
}

std::string make_dir(const std::string &dir_name)
{
    std::string dir_path = std::string(getenv("USERPROFILE")) + "\\Desktop\\" + dir_name;

    if (access(dir_path.c_str(), 0) != 0) {
        mkdir(dir_path.c_str());
    }

    return dir_path;
}

std::string ApplicantDB::createDB(const std::string &db_name)
{
    std::string path = make_dir("DB") + "\\" + db_name + ".bin";
    file = fopen(path.c_str(), "ab+");
    if (!file) {
        throw std::runtime_error("Failed to create the file");
    }
    fclose(file);

    return path;
}

ApplicantDB::~ApplicantDB()
{
    if (file != nullptr) fclose(file);
}

void ApplicantDB::deleteDB()
{
    if (file != nullptr) fclose(file);
    remove(path_to_file.c_str());
}

void ApplicantDB::addApplicant(const Applicant &new_applicant)
{
    if (file == nullptr) {
        throw std::runtime_error("Table doesn't exist");
    }

    fseek(file, 0, SEEK_END);
    fwrite(&new_applicant, sizeof(new_applicant), 1, file);
}

void ApplicantDB::print() const
{
    std::cout << std::endl;
    fseek(file, 0, SEEK_END);
    std::cout << "| Surname"
              << " | "
              << "Initials"
              << " | "
              << "Gender"
              << " | "
              << "School Number"
              << " | "
              << "Has Medal"
              << " | "
              << "Math Score"
              << " | "
              << "Physics Score"
              << " | "
              << "Chemistry Score"
              << " | "
              << "Essay Score"
              << " | "
              << "Essay Pass"
              << " |" << std::endl;
    std::cout << "|___________|___________|________|_______________|________|___________|____________|______________|___________|__________|" << std::endl;
    fseek(file, 0, SEEK_SET);
    Applicant applicant;

    while (fread(&applicant, sizeof(Applicant), 1, file) == 1) {
        applicant.print();
        std::cout << "|___________|___________|________|_______________|________|___________|____________|______________|___________|__________|" << std::endl;
    }
}

void ApplicantDB::findFemaleApplicantsWithSameScoresAndFailThreshold(double passThreshold) const
{
    fseek(file, 0, SEEK_SET);
    Applicant applicant;
    int counter = 0;

    while (fread(&applicant, sizeof(Applicant), 1, file) == 1) {
        if (applicant.gender == 'F' &&
            applicant.mathScore == passThreshold &&
            applicant.physicsScore == passThreshold &&
            applicant.chemistryScore == passThreshold &&
            applicant.mathScore + applicant.physicsScore + applicant.chemistryScore < passThreshold) {
            ++counter;
            std::cout << "Female Applicant with the same scores and failed threshold: " << applicant.surname << std::endl;
        }
    }

    if (counter == 0) {
        std::cout << "No female applicants with the specified criteria found." << std::endl;
    }
}
