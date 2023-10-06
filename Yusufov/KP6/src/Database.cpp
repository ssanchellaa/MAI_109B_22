#include "../include/Database.hpp"
#include <filesystem>

Database::Database(const std::string &filename) {
    path = create_db(filename);
}

std::string make_dir(const std::string &dir_name) {
    std::string dir_path = std::string(getenv("HOME")) + "/Documents/" + dir_name;

    if (!std::filesystem::is_directory(dir_path.c_str())) {
        std::filesystem::create_directories(dir_path.c_str());
    }

    return dir_path;
}

std::string Database::create_db(const std::string &filename) {
    std::fstream file;
    std::string curr_path = make_dir("Databases") + "/" + filename + ".dat";
    file.open(curr_path, std::ios::app);
    if (!file) {
        throw std::runtime_error("Problems with file creation");
    }
    file.close();
    return curr_path;
}

void Database::delete_db() {
    std::fstream file;
    if (file) file.close();
    remove(path.data());
}

void Database::add_row(const Row &applicant) {
    std::fstream file;
    if (!file) {
        throw std::runtime_error("File doesn't exist");
    }
    file.open(path.data(), std::ios::out | std::ios::app);
    file << applicant;
    file.close();
}


void Database::print() const {

    std::fstream file;
    std::cout
            << std::setw(20) << std::left << "Surname" << "\t|\t"
            << std::setw(8) << std::left << "Initials" << "\t|\t"
            << std::setw(8) << std::left << "Gender" << "\t|\t"
            << std::setw(15) << std::left << "School number" << "\t|\t"
            << std::setw(10) << std::left << "Has medal" << "\t|\t"
            << std::setw(6) << std::left << "Exam1" << "\t|\t"
            << std::setw(6) << std::left << "Exam2" << "\t|\t"
            << std::setw(6) << std::left << "Exam3" << "\t|\t"
            << std::setw(15) << std::left << "Passed writing" << std::endl;
    std::cout << "___________________________________________________________________________________________\n";

    file.open(path.data(), std::ios::in);
    Row applicant;
    while (file.peek() != EOF) {
        file >> applicant;
        applicant.print();
    }
    std::cout << "___________________________________________________________________________________________\n";
    file.close();
}


void Database::lab_task() const {
    std::cout << "Find applicants who are women and have equal results on 2 exams" << std::endl;

    std::cout << "___________________________________________________________________________________________\n";

    std::fstream file;
    file.open(path.data(), std::ios::in);
    Row applicant;

    std::cout
            << std::setw(20) << std::left << "Surname" << "\t|\t"
            << std::setw(8) << std::left << "Initials" << "\t|\t"
            << std::setw(8) << std::left << "Gender" << "\t|\t"
            << std::setw(15) << std::left << "School number" << "\t|\t"
            << std::setw(10) << std::left << "Has medal" << "\t|\t"
            << std::setw(6) << std::left << "Exam1" << "\t|\t"
            << std::setw(6) << std::left << "Exam2" << "\t|\t"
            << std::setw(6) << std::left << "Exam3" << "\t|\t"
            << std::setw(15) << std::left << "Passed writing" << std::endl;
    std::cout << "___________________________________________________________________________________________\n";

    while (file.peek() != EOF) {
        file >> applicant;
        if (applicant.gender == 'F' && (applicant.exam1 == applicant.exam2 || applicant.exam2 == applicant.exam3 || applicant.exam1 == applicant.exam3)) {
            applicant.print();
        }
    }
    file.close();
}