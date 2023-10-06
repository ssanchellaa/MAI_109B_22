
#ifndef TABLEENTRY_HPP
#define TABLEENTRY_HPP

#include <string>

class TableEntry {
public:
    int integerKey;
    char letterKey;
    std::string text;

    TableEntry(int integerKey, char letterKey, const std::string& text);
};
