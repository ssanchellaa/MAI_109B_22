#ifndef EXPRESSIONTREEHPP
#define EXPRESSIONTREEHPP

#include "Node.hpp"
#include <iostream>
#include <string>

class ExpressionTree{
private:
    Node* root = nullptr;

public:
    ExpressionTree();
    ExpressionTree(const std::string&);
    ~ExpressionTree();
    void delete_tree(Node*);

    Node* get_root() const;

    uint8_t get_priority(const char) const;
    bool is_operator(const char) const;
    std::string do_postfix(const std::string&);
    Node* create_tree(const std::string& = "");
    void task();
    Node* task(Node*);

    void print_postfix(Node*) const;
    void print_infix(Node*) const;
    void print_tree(Node*, const uint64_t = 0) const;
};

#include "../src/ExpressionTree.cpp"
#endif //EXPRESSIONTREEHPP