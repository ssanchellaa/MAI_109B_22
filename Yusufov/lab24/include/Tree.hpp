#ifndef TREE_HPP
#define TREE_HPP

#include "Node.hpp"
#include "../../KP7/include/Vector.hpp"
#include <string>

class Tree{
public:

    Tree();
    Tree(const std::string& infStr);

    bool isOperator(char) const;
    size_t getPriority(char) const;
    void pasteOperandNode(Vector<Node<std::string>*>&, char);

    void buildBinaryTree();
    void swapInfStr(Node<std::string>* = nullptr);

    void print(Node<std::string>* = nullptr, size_t = 0) const;
    void clear(Node<std::string>* = nullptr);
    void changeInfStr(Node<std::string>* = nullptr);

    ~Tree();

private:
    Node<std::string>* root;
    std::string infStr;
};

#include "../src/Tree.cpp"

#endif