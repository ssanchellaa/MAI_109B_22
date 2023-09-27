#ifndef STACKHPP
#define STACKHPP

#include "../../KP7/include/Vector.hpp"
#include <iostream>

template <typename T>
class Stack{
private:
    Vector<T> stack;

public:
    Stack() = default;
    ~Stack() = default;

    size_t size() const;
    bool empty() const;
    void push(const T&);
    void pop();
    T& top();
    const T& top() const;
};

#include "../src/Stack.cpp"
#endif //STACKHPP