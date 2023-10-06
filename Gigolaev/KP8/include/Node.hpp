#pragma once
class Node
{
    public:
        char data;
        Node* next;
        Node();
        Node(char _data);
        Node(char _data, Node* _next);
};
#include "../src/Node.cpp"