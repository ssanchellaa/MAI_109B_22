#include <iostream>
#include "../include/List.hpp"
int main()
{
    Node* a = new Node('a');
    Node* b = new Node('b');
    Node* c = new Node('c');
    Node* d = new Node('d');
    Node* e = new Node('e');
    List* list = new List();
    list->Insert(a);
    list->Insert(a, c);
    list->Insert(b);
    list->Insert(c, d);
    list->Insert(d, e);
    std::cout << *list;
    list->ChangePlaces();
    std::cout << *list;
    delete list;
    return 0;
}