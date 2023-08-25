#ifndef LAB_TREE_H
#define LAB_TREE_H

template<typename T>
Tree<T>::Tree(Node<T>* const node): root(node) {}

template<typename T>
Node<T> *Tree<T>::get_root() {
    return this->root;
}

template<typename T>
void Tree<T>::recalculateHeight(Node<T> *node) const {
    int templeft, tempright= 0;

    if (node == nullptr) {
        return;
    }

    templeft = (nullptr != node->get_left()) ? node->get_left()->get_height() : 0;
    tempright = (nullptr != node->get_right()) ? node->get_right()->get_height(): 0;

    node -> set_height((templeft >= tempright) ? templeft + 1: tempright + 1);


    recalculateHeight(node->get_parentNode());

}

template<typename T>
void Tree<T>::recalculateTreeHeight(Node<T> *node) const {

    if (node->get_left() == nullptr || node->get_right() == nullptr) {
        recalculateHeight(node);
        return;
    }
    recalculateTreeHeight(node->get_left());
    recalculateTreeHeight(node->get_right());

}



template<typename T>
bool Tree<T>:: isAVLtree(Node<T> *node){
    if (node == nullptr) {
        return true;
    }

    int HLeft = (node->get_left() == nullptr) ? 0 : node->get_left()->get_height();
    int RLeft = (node->get_right() == nullptr) ? 0 : node->get_right()->get_height();

    if ((abs(HLeft - RLeft)) > 1) return false;

    return (isAVLtree(node->get_right()) && isAVLtree(node->get_left()));

}

template<typename T>
void Tree<T>::PrintResult(Node<T> *node){
    if (isAVLtree(node)){
        std::cout<<"This is AVL tree"<<std::endl;
    }else{
        std::cout<<"This is not AVL tree"<<std::endl;
    }
}

//если нет корня, добавили корень, затем добавляем листья
template<typename T>
void Tree<T>::insert(const T &value) {
    if (root == nullptr) {
        root = new Node<T>(value);
        this->recalculateHeight(root);
        return;
    }
    add_leaf(root, value);
}

template<typename T>
void Tree<T>::delete_node(const T &value) {
    root = root->delete_node(root, value);
    recalculateTreeHeight(root);
}

template<typename T>
void Tree<T>::print_tree() const {
    root->print_nodes(root, 0);
}

//добавление листьев
template<typename T>
void Tree<T>::add_leaf(Node<T> *current_node, const T &value) {
    Node<T> *newNode;
    while (true) {
        if (value < current_node->get_value()) {
            if (current_node->get_left() == nullptr) {
                newNode = new Node<T>(value, current_node);
                current_node->set_left(newNode);
                break;
            } else {
                current_node = current_node->get_left();
            }
        } else if (value > current_node->get_value()) {
            if (current_node->get_right() == nullptr) {
                newNode = new Node<T>(value, current_node);
                current_node->set_right(newNode);
                break;
            } else {
                current_node = current_node->get_right();
            }
        } else {
            std::cout << "Existing node with same value found. Please use another value." << std::endl;
            break;
        }
    }
    recalculateHeight(newNode);
}

template<typename T>
std::ostream &operator<<(std::ostream &out, const Tree<T> &t)
{
    t.root->Node<T>::print_nodes(out, t.root, 0);
    return out;
}

template<typename T>
void Tree<T>::bypass() const {
    root->bypass(root);
}

template<typename T>
Tree<T>::~Tree() {
    root->delete_branch(root);
    
}

#include "../include/Tree.hpp"

#endif //LAB_TREE_H
