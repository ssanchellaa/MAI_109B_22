#ifndef LISTHPP
#define LISTHPP

#include "FriendClass.hpp"
#include "Iterator.hpp"
#include <iostream>

template <typename T>
class List{
    friend class Iterator<T>;
private:
    Node<T>* head = nullptr;
    size_t sz = 0;

public:
    List() = default;
    List(const List<T>&);
    ~List();

    Iterator<T> begin() const;
    Iterator<T> end() const;

    void push_back(const T& val);
    void push_front(const T& val);
    void pop_back();
    void pop_front();

    void insert(const Iterator<T>& it, const T& val);
    void erase(const Iterator<T>& start, const Iterator<T>& end);

    template <typename... Args>
    void emplace_back(const Args&...);

    size_t size() const;
    bool empty() const;

    void task(uint64_t num);
    
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const List<U>& list);
};

#include "../src/List.cpp"
#endif //LISTHPP