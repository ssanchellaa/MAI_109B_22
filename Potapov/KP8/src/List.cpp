#include "../include/List.hpp"

template<typename T>
List<T>::List(const List<T>& other) {
    Iterator<T> it = other.begin();
    for (int64_t i = 0; i < other.size() && it != other.end(); ++i, ++it) {
        push_back(it.node->data);
    }
}

template<typename T>
List<T>::~List() {
    if (head == nullptr)
        return;
    Node<T>* cur_node = head->next;
    while (cur_node != head) {
        Node<T>* to_del = cur_node;
        cur_node = cur_node->next;
        delete to_del;
    }
    delete head;
}

template <typename T>
Iterator<T> List<T>::begin() const{
    return Iterator<T>(head);
}

template <typename T>
Iterator<T> List<T>::end() const{
    return Iterator<T>(head->previous);
}

template <typename T>
void List<T>::push_back(const T& val){
    if (head == nullptr) {
        head = new Node<T>(val);
        head->next = head;
        head->previous = head;
        ++sz;
        return;
    }

    Node<T>* cur_last_node = head->previous;

    Node<T>* new_last_node = new Node<T>(val, cur_last_node, head);
    cur_last_node->next = new_last_node;
    head->previous = new_last_node;
    ++sz;
}

template <typename T>
void List<T>::push_front(const T& val){
    push_back(val);
    head = head->previous;
}

template <typename T>
void List<T>::pop_back(){
    if (head == nullptr) return;

    if (sz >= 2) {
        Node<T>* cur_last = head->prev;
        Node<T>* new_last = cur_last->prev;

        new_last->next = head;
        head->previous = new_last;
        delete cur_last;
        --sz;
    } else if (sz == 1) {
        delete head;
        head = nullptr;
        --sz;
    }
}

template <typename T>
void List<T>::pop_front(){
    if (head == nullptr) return;
    head = head->next;
    pop_back();
}

template <typename T>
void List<T>::insert(const Iterator<T>& it, const T& val){
    if (it != end()) {
        Node<T>* cur_node = it.node;
        Node<T>* prev_node = cur_node->prev;

        Node<T>* new_node = new Node<T>(val, prev_node, cur_node);
        prev_node->next = new_node;
        cur_node->prev = new_node;

        if (head == it.node) {
            head = new_node;
        }
        ++sz;
        return;
    } else {
        push_back(val);
    }
}

template <typename T>
void List<T>::erase(const Iterator<T>& start, const Iterator<T>& end){
    if (head == nullptr) return;

    if (sz == 1){
        pop_back();
        return;
    }

    Iterator<T> erase_it = start;
    ++erase_it;
    start.node->next = end.node;
    end.node->previous = start.node;

    while (erase_it != end){
        if (erase_it == this->begin()) start = end.node;
        Node<T>* to_del = erase_it.node;
        ++erase_it;
        delete to_del;
        to_del = nullptr;
    }
}

template <typename T>
template <typename... Args>
void List<T>::emplace_back(const Args&...args){
    this->push_back(T(args...));
}

template<typename T>
size_t List<T>::size() const {
    return sz;
}

template<typename T>
bool List<T>::empty() const {
    return sz == 0;
}

template <typename T>
void List<T>::task(uint64_t num){
    T last_val = head->previous->data;
    for (uint64_t i = 0; i != num; ++i){
        push_front(last_val);
    }
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