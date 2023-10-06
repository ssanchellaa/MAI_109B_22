#include "../include/Table.hpp"
#include <iostream>
#include <string>

int main(){
    Table<std::string> table;

    table.insert("77.77777", "SECHENOVKA");
    table.insert("00.00000", "MAI");
    table.insert("11.11111", "MAI");
    table.insert("88.88888", "RANHIGS");
    table.insert("22.22222", "MGU");
    table.insert("66.66666", "SINERGIYA");
    table.insert("44.44444", "MGSU");
    table.insert("55.55555", "SPBGU");
    table.insert("99.99999", "RUDN");
    table.insert("33.33333", "MGTU");

    table.sort();
    table.print();

    return 0;
}