#ifndef ITERATORHPP
#define ITERATORHPP

#include "Node.hpp"
#include <iostream>

template <typename T>
class List;

template <typename T>
class Iterator{
    friend class List<T>;
private:
    Node<T>* node;
public:
    Iterator() = default;
    Iterator(Node<T>*);
    ~Iterator() = default;

    Iterator<T> operator++();
    Iterator<T> operator+(int64_t);

    T& operator*();
    const T& operator*() const;

    bool operator==(Iterator<T>) const;
    bool operator!=(Iterator<T>) const;
};

#include "../src/Iterator.cpp"
#endif //ITERATORHPP