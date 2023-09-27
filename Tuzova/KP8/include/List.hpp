#ifndef LIST_HPP_INCLUDED
#define LIST_HPP_INCLUDED

#include <iostream>
#include "Node.hpp"

using namespace std;

class List {
private:
    Node* head;
public:
    List();

    void insert(char data);

    void remove(char data);

    int length();

    void print();

    void removeBeforeAfter(char data);
    
    ~List();
};

#include "../src/List.cpp"

#endif


