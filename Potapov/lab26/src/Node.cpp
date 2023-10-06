#include "../include/Node.hpp"

template <typename T>
Node<T>::Node(): val(0), next(nullptr){}

template <typename T>
Node<T>::Node(const T& val): val(val), next(nullptr){}

template <typename T>
Node<T>::Node(const T& val, Node<T>* next): val(val), next(next){}