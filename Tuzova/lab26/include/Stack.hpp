#ifndef STACK_HPP_INCLUDED
#define STACK_HPP_INCLUDED

#include <iostream>
#include <cstdlib>
using namespace std;

#define SIZE 10
class Stack {
    int *arr;
    int top;
    int capacity;

public:
    Stack(int size = SIZE);
    ~Stack();

    void push(int);
    int pop();
    int peek();

    int size();
    bool isEmpty();
    bool isFull();
    
    void print();

    void moveToFront();
};

#include "../src/Stack.cpp"

#endif
