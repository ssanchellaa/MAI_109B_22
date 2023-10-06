#ifndef LISTHPP
#define LISTHPP

#include "Node.hpp"
#include "Iterator.hpp"
#include <iostream>
#include <initializer_list>

template <typename T>
class Iterator;

template <typename T>
class List{
    friend class Iterator<T>;
private:
    Node<T>* head;
    size_t sz;
public:
    List();
    List(const std::initializer_list<T>&);
    ~List();

    Iterator<T> begin() const;
    Iterator<T> end() const;

    size_t size() const;
    bool empty() const;
    void push_back(const T&);
    void pop_back();
    void bubble_sort();

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const List<U>& list);
};

#include "../src/List.cpp"
#endif //LISTHPP