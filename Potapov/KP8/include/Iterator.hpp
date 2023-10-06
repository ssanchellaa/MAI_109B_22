#ifndef ITERATORHPP
#define ITERATORHPP

#include "FriendClass.hpp"
#include "Node.hpp"

template <typename T>
class Iterator{
    friend class List<T>;
private:
    Node<T>* node;

public:
    Iterator() = default;
    Iterator(Node<T>* node);
    ~Iterator() = default;

    Iterator<T> operator++();
    Iterator<T> operator--();

    Iterator<T> operator+(int64_t num);
    Iterator<T> operator-(int64_t num);

    T& operator*();
    const T& operator*() const;

    bool operator==(Iterator<T> left) const;
    bool operator!=(Iterator<T> left) const;
};

#include "../src/Iterator.cpp"
#endif //ITERATORHPP