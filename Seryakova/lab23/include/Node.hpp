#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED
#include <iostream>

template <typename T>
class  Node {
private:
    T value;
    Node<T> *left = nullptr;
    Node<T> *right = nullptr;
    T height;
    Node<T> *parentNode = nullptr;

public:
    Node() = default;
    explicit Node(const T &value);
    explicit Node(const T &value, Node<T> *parentNode);

    T get_value() const;
    void set_value(T value);
    Node<T> *get_left() const;
    void set_left(Node<T> *left);
    Node<T>*get_right() const;
    void set_right(Node<T> *right);

    int get_height() const;
    void set_height(T height);
    void print_nodes(std::ostream &out, Node<T> *node, int64_t height) const;
    void print_nodes(Node<T> *node, int64_t height) const;

    Node<T> *delete_node(Node<T> *current_node, const T &value);

    Node<T> *min_value_node(Node<T>* const node) const;
    void bypass(Node<T> *node) const;
    void delete_branch(Node<T> *current_node);
    ~Node() = default;


    Node<T> *get_parentNode() const;

};


#endif
