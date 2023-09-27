#include "../include/DataBase.hpp"
#include "../include/RowTable.hpp"
#include <iostream>

int main(int argc, char* argv[]){
    DataBase db("MyBDFile");

    RowTable stud1("Zaitsev V.", "male", 228, 5, 5, 5, 5, 5, 5);
    RowTable stud2("Bortakovski A.", "male", 337, 5, 4, 5, 5, 5, 5);
    RowTable stud3("Pegachkova E.", "female", 109, 5, 5, 4, 5, 4, 5);
    RowTable stud4("Alekseev N.", "male", 100, 3, 3, 4, 4, 2, 4);
    RowTable stud5("Martushova J.", "female", 109, 5, 5, 5, 5, 5, 5);
    RowTable stud6("Bulakina M.", "female", 105, 4, 5, 3, 2, 5, 5);
    RowTable stud7("Smirnova L.", "female", 108, 5, 3, 5, 4, 5, 2);
    RowTable stud8("Ivanova T.", "female", 108, 5, 5, 3, 5, 4, 5);
    RowTable stud9("Bitykov J.", "male", 109, 5, 5, 5, 5, 5, 5);
    RowTable stud10("Garibjan B.", "male", 109, 5, 5, 5, 5, 5, 5);

    db.add_data(stud1);
    db.add_data(stud2);
    db.add_data(stud3);
    db.add_data(stud4);
    db.add_data(stud5);
    db.add_data(stud6);
    db.add_data(stud7);
    db.add_data(stud8);
    db.add_data(stud9);
    db.add_data(stud10);

    for (size_t i = 1; i < argc; ++i){
        if (argv[i] == "-f"){
            db.print();
        } else if(argv[i] == "-p"){
            db.find_max_GPA();
        }
    }

    return 0;
}