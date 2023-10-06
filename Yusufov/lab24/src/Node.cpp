#include "../include/Node.hpp"

template<typename T>
Node<T>::Node(T data){
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
}

template<typename T>
Node<T>::Node(T data, Node* left, Node* right){
    this->data = data;
    this->left = left;
    this->right = right;
}