#ifndef NODEHPP
#define NODEHPP

class ExpressionTree;

class Node{
    friend class ExpressionTree;
private:
    char data;
    Node* left;
    Node* right;

public:
    Node();
    Node(const char);
    Node(const char, Node*, Node*);
};

#include "../src/Node.cpp"
#endif //NODEHPP