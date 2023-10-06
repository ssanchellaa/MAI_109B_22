#include "../include/Iterator.hpp"

template <typename T>
Iterator<T>::Iterator(Node<T>* node): node(node){}

template <typename T>
Iterator<T> Iterator<T>::operator++(){
    if (node) node = node->next;
    return *this;
}

template <typename T>
Iterator<T> Iterator<T>::operator--(){
    if (node) node = node->previous;
    return *this;
}

template <typename T>
Iterator<T> Iterator<T>::operator+(int64_t num){
    if (num > 0) {
        while (num-- && node) {
            node = node->next;
        }
    } else if (num < 0) {
        while (num++ && node) {
            node = node->previous;
        }
    }
    return *this;
}

template <typename T>
Iterator<T> Iterator<T>::operator-(int64_t num){
    return *this + (-num);
}

template <typename T>
T& Iterator<T>::operator*(){
    return node->data;
}

template <typename T>
const T& Iterator<T>::operator*() const{
    return node->data;
}

template <typename T>
bool Iterator<T>::operator==(Iterator<T> left) const{
    return this->node == left.node;
}

template <typename T>
bool Iterator<T>::operator!=(Iterator<T> left) const{
    return !(this->node == left.node);
}