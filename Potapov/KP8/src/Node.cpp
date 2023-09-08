#include "../include/Node.hpp"

template <typename T>
Node<T>::Node(): data(0){}

template <typename T>
Node<T>::Node(const T& data): data(data){}

template <typename T>
Node<T>::Node(const T& data, Node<T>* previous, Node<T>* next): data(data), previous(previous), next(next){}