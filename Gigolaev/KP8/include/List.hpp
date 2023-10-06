#pragma once
#include <iostream>
#include "./Node.hpp"

class List
{
    private:
        Node* head;
        Node* barrier;
    public:
        List();
        List(Node* _head);
        List(Node* _head, Node* barrier);
        ~List();
        bool Insert(Node* positionNode, Node* newNode);
        bool Insert(Node* newNode);
        bool Remove(Node* node);
        bool ChangePlaces();
        size_t Size() const;
        friend std::ostream& operator<<(std::ostream& os, List& list);
};

#include "../src/List.cpp"