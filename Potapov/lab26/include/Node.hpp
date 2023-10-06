#ifndef NODEHPP
#define NODEHPP

template <typename T>
class List;

template <typename T>
class Iterator;

template <typename T>
class Node{
    friend class List<T>;
    friend class Iterator<T>;
private:
    T val;
    Node* next;
public:
    Node();
    Node(const T&);
    Node(const T&, Node<T>*);
    ~Node() = default;
};

#include "../src/Node.cpp"
#endif //NODEHPP