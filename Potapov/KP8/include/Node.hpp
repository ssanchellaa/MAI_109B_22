#ifndef NODEHPP
#define NODEHPP

#include <iostream>
#include "FriendClass.hpp"

template <typename T>
class Node{
    friend class Iterator<T>;
    friend class List<T>;
private:
    T data;
    Node<T>* previous;
    Node<T>* next;

public:
    Node();
    Node(const T& data);
    Node(const T& data, Node<T>* previous, Node<T>* next);
};

#include "../src/Node.cpp"
#endif //NODEHPP