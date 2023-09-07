#include "../include/DataBase.hpp"
#include "../include/Triple.hpp"
#include "../../KP7/include/Vector.hpp"
#include <direct.h>
#include <io.h>
#include <iostream>
#include <iomanip>
#include <string>

DataBase::DataBase(const std::string& file_name){
    file_path = create_file(file_name);
    file = fopen(file_path.c_str(), "wb+");
}

DataBase::~DataBase(){
    if (file != nullptr) fclose(file);
}

const std::string make_dir(const std::string& dir_name){
    std::string dir_path = std::string(getenv("USERPROFILE")) + "\\Desktop\\" + dir_name;

    if (access(dir_path.c_str(), 0) != 0){
        mkdir(dir_path.c_str());
    }

    return dir_path;
}

const std::string DataBase::create_file(const std::string& file_name){
    std::string path = make_dir("DataBase") + "\\" + file_name + ".bin";
    file = fopen(path.c_str(), "ab+");
    if (!file){
        throw std::runtime_error("Failed to create the file");
    }

    std::string header = "My Data Base";
    fwrite(header.c_str(), header.size(), 1, file);
    fclose(file);

    return path;
}

void DataBase::add_data(const RowTable& student){
    if (file == nullptr){
        throw std::runtime_error("File doesn't exist");
    }

    fseek(file, 0, SEEK_END);
    fwrite(&student, sizeof(student), 1, file);
}

void DataBase::print() const{
    std::cout << "\n| " << "   Student   " << " | "  << " Sex " << " | " << "Group Number" << " | " << "Computer Science" << " | " <<
                "Programming Practice" << " | " << "Linear Algebra" << " | " << "Math Analysis" << " | " << "English" << " | " <<
                "Philosophy" << " |\n";
    std::cout << "+-" << "-------------" << "-+-" << "-----" << "-+-" << "------------" << "-+-" << "----------------" << "-+-" <<
                "--------------------" << "-+-" << "--------------" << "-+-" << "-------------" << "-+-" << "-------" << "-+-" <<
                "----------" << "-+\n";

    fseek(file, 0, SEEK_SET);
    RowTable student;
    while (fread(&student, sizeof(RowTable), 1, file) == 1){
        student.print();
        std::cout << "+-" << "-------------" << "-+-" << "-----" << "-+-" << "------------" << "-+-" << "----------------" << "-+-" <<
                    "--------------------" << "-+-" << "--------------" << "-+-" << "-------------" << "-+-" << "-------" << "-+-" <<
                    "----------" << "-+\n";
    }
} 

void DataBase::find_max_GPA() const{
    if (file == nullptr){
        throw std::runtime_error("File doesn't exist");
    }

    fseek(file, 0, SEEK_SET);
    RowTable student;
    Vector<Triple<uint64_t, double, uint16_t>> students;
    while (fread(&student, sizeof(RowTable), 1, file) == 1){
        if (student.sex == "female"){
            bool group_found = false;
            for (size_t i = 0; i != students.size(); ++i){
                if (students[i].first ==  student.group_number){
                    group_found = true;
                    students[i].second += (student.get_GPA());
                    ++students[i].third;
                }
            }
            if (!group_found){
                students.push_back(Triple<uint64_t, double, uint16_t>(student.group_number, student.get_GPA(), 1));
            }
        }
    }

    double max_GPA = 0;
    uint64_t max_GPA_group_number = 0;
    for (size_t i = 0; i != students.size(); ++i){
        double group_GPA = students[i].second / students[i].third;
        if (group_GPA > max_GPA){
            max_GPA = group_GPA;
            max_GPA_group_number = students[i].first;
        }
    }

    std::cout << "\nThe group in which female students have the maximum GPA: " << max_GPA_group_number << "\n";
}

void DataBase::delete_file(){
    if (file != nullptr) fclose(file);
    remove(file_path.c_str());
}