#ifndef NODE_HPP
#define NODE_HPP

template<typename T>
class Node{
public:

    Node() = delete;
    Node(T);
    Node(T, Node*, Node*);

    T data;
    Node* left;
    Node* right;
};

#include "../src/Node.cpp"

#endif