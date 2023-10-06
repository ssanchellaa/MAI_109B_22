#include "../include/List.hpp"

template <typename T>
List<T>::List(){
    head = nullptr;
    sz = 0;
}

template <typename T>
List<T>::List(const std::initializer_list<T>& list){
    head = nullptr;
    sz = 0;
    for (T elem: list){
        push_back(elem);
    }
}

template <typename T>
List<T>::~List(){
    if (head == nullptr) return;

    Node<T>* cur = head->next;
    while (cur != nullptr){
        Node<T>* to_delete = cur;
        cur = cur->next;
        delete to_delete;
    }
    delete head;
}

template <typename T>
Iterator<T> List<T>::begin() const{
    return Iterator<T>(head);
}

template <typename T>
Iterator<T> List<T>::end() const{
    Node<T>* end_node = head;
    while (end_node->next != nullptr){
        end_node = end_node->next;
    }
    return Iterator<T>(end_node);
}

template <typename T>
size_t List<T>::size() const{
    return this->sz;
}

template <typename T>
bool List<T>::empty() const{
    return this->sz == 0;
}

template <typename T>
void List<T>::push_back(const T& value){
    if (head == nullptr){
        head = new Node<T>(value, nullptr);
        ++sz;
        return;
    }

    Iterator<T> end_it = end();
    end_it.node->next = new Node<T>(value, nullptr);
    ++sz;
    return;
}

template <typename T>
void List<T>::pop_back(){
    if (head == nullptr) return;

    if (sz == 1){
        delete head;
        head = nullptr;
        --sz;
        return;
    }

    Iterator<T> it = begin();
    while (it.node->next->next != nullptr){
        ++it;
    }
    Node<T>* to_delete = it.node->next;
    delete to_delete;
    to_delete = nullptr;
    --sz;
    return;
}

template <typename T>
void List<T>::bubble_sort(){
    if (head == nullptr || head->next == nullptr) {
        return;
    }
    bool swapped;
    do {
        swapped = false;
        Node<T>* cur = head;
        Node<T>* prev = nullptr;
        Node<T>* next_node = cur->next;
        while (next_node != nullptr) {
            if (cur->val > next_node->val) {
                if (prev != nullptr) {
                    prev->next = next_node;
                } else {
                    head = next_node;
                }
                cur->next = next_node->next;
                next_node->next = cur;
                prev = next_node;
                next_node = cur->next;
                swapped = true;
            } else {
                prev = cur;
                cur = cur->next;
                next_node = cur->next;
            }
        }
    } while (swapped);
}

template <typename U>
std::ostream& operator<<(std::ostream& os, const List<U>& list){
    if (list.head == nullptr) return os;

    Iterator<U> it;
    size_t i;
    for (it = list.begin(), i = 0; i < list.size(); ++it, ++i) {
        os << *it << " ";
    }
    os << std::endl;

    return os;
}