#include "../include/Stack.hpp"
#include <iostream>

template <typename T>
size_t Stack<T>::size() const{
    return this->stack.size();
}

template <typename T>
bool Stack<T>::empty() const{
    return this->stack.empty();
}

template <typename T>
void Stack<T>::push(const T& val){
    this->stack.push_back(val);
}

template <typename T>
void Stack<T>::pop(){
    this->stack.pop_back();
}

template <typename T>
T& Stack<T>::top(){
    return this->stack.back();
}

template <typename T>
const T& Stack<T>::top() const{
    return this->stack.back();
}