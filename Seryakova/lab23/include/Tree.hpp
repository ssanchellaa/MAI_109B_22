

#ifndef TREE_HPP_INCLUDED
#define TREE_HPP_INCLUDED

#include "../include/Node.hpp"
#include "../src/Node.cpp"

template <typename T>
class Tree {
private:

    Node<T> *root = nullptr;
public:
    Tree() = default;
    explicit Tree(Node<T>* node);
    Node<T> *get_root();
    void insert(const T &value);
    void delete_node(const T &value);
    void recalculateHeight(Node<T> *node) const;
    void recalculateTreeHeight(Node<T> *node) const;
    void print_tree() const;
    void bypass() const;
    void add_leaf(Node<T> *current_node, const T &value);
    
    bool isAVLtree(Node<T> *node);
    void PrintResult(Node<T> *node);

     template<typename U>
     friend std::ostream &operator<<(std::ostream &out, const Tree<U> &t);

    ~Tree();
};;


#endif
