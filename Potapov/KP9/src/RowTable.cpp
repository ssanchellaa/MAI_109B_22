#include "../include/RowTable.hpp"

template <typename T>
RowTable<T>::RowTable(const T& key, const std::string& data): key(key), data(data){}

template <typename T>
T& RowTable<T>::get_key(){
    return this->key;
}

template <typename T>
std::string& RowTable<T>::get_data(){
    return this->data;
}

template <typename T>
bool RowTable<T>::operator<(const RowTable<T>& other) const{
    return this->key < other.key;
}