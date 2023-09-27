#ifndef LAB_NODE_H
#define LAB_NODE_H
#include "../include/Node.hpp"


template<typename T>
Node<T>::Node(const T &value): value(value) {}

template<typename T>
Node<T>::Node(const T &value, Node<T> *parentNode) {
    this->value = value;
    this->parentNode = parentNode;
}

template<typename T>
T Node<T>::get_value() const {
    return this->value;
}

template<typename T>
Node<T> *Node<T>::get_left() const {
    return this->left;
}

template<typename T>
void Node<T>::set_left(Node<T> *left) {
    Node::left = left;
}

template<typename T>
Node<T> *Node<T>::get_right() const {
    return this->right;
}
template<typename T>
void Node<T>::set_right(Node<T> *right) {
    Node::right = right;
}

template<typename T>
int Node<T>::get_height() const {
    return this->height;
}

template<typename T>
void Node<T>::print_nodes(std::ostream &out, Node<T> *node, int64_t height) const {
    if (node != nullptr) {
        print_nodes(out, node->get_right(), height + 1);
        for (int64_t i = 0; i < height; ++i) {
            out << '\t';
        }
        out << node->value << '\n';
        print_nodes(out, node->get_left(), height + 1);
    }
}

template<typename T>
void Node<T>::print_nodes(Node<T> *node, int64_t height) const {
    if (node != nullptr) {
        print_nodes(node->right, height + 1);
        for (int64_t i = 0; i < height; ++i) {
            std::cout << '\t';
        }
        std::cout << node->value << " "<< node->height<<'\n';
        print_nodes(node->get_left(), height + 1);
    }
}

//возвращает указатель на узел с минимальным значением в поддереве, начинающемся с узла node.
template<typename T>
Node<T> *Node<T>::min_value_node(Node<T>* const node) const {
    Node<T> *current = node;
    // Go down to search for leftmost leaf
    while (current && current->get_left() != nullptr)
        current = current->get_left();
    return current;
}

//выводит значения всех узлов дерева в порядке обхода в глубину.
template<typename T>
void Node<T>::bypass(Node<T> *node) const {
    if (node == nullptr) {
        return;
    }
    std::cout << node->value << std::endl;
    bypass(node->get_left());
    bypass(node->get_right());
}

template<typename T>
Node<T> *Node<T>::delete_node(Node<T> *current_node, const T &value) {
    if (current_node == nullptr)
        return current_node;

    // If the value is smaller than the current_node's
    // value, then it is in left subtree
    if (value < current_node->value)
        current_node->left = delete_node(current_node->get_left(), value);

        // If the value is greater than the current_node's
        // value, then it is in right subtree
    else if (value > current_node->value)
        current_node->right = delete_node(current_node->get_right(), value);

        // If value is same as current_node's value, then this node should be deleted
    else {
        // Node has no child
        if (current_node->left == nullptr and current_node->get_right() == nullptr) {
            delete current_node;
            return nullptr;
        }
            // Node with only one child or no child
        else if (current_node->left == nullptr) {
            Node<T> *temp = current_node->get_right();
            delete current_node;
            return temp;
        } else if (current_node->right == nullptr) {
            Node<T> *temp = current_node->get_left();
            delete current_node;
            return temp;
        }

        // If node has two children, then get the smallest node in the right subtree
        Node<T> *temp = min_value_node(current_node->get_right());
        // Copy it's content to this node
        current_node->value = temp->value;
        // Delete the temp node
        current_node->set_right(delete_node(current_node->get_right(), temp->value));
    }
    return current_node;
}

template<typename T>
void Node<T>::delete_branch(Node<T> *current_node) {
    if (current_node == nullptr)
        return;
    delete_branch(current_node->get_left());
    delete_branch(current_node->get_right());
    delete current_node;
}

template<typename T>
void Node<T>::set_value(T value) {
    Node::value = value;
}

template<typename T>
void Node<T>::set_height(T height) {
    Node::height = height;
}

template<typename T>
Node<T> *Node<T>::get_parentNode() const {
    return parentNode;
}


#endif //LAB_NODE_H
