#include "../include/Triple.hpp"

template <typename T, typename U, typename K>
Triple<T, U, K>::Triple(const T& first, const U& second, const K& third): first(first), second(second), third(third){}

template <typename T, typename U, typename K>
T& Triple<T, U, K>::get_first(){
    return this->first;
}

template <typename T, typename U, typename K>
U& Triple<T, U, K>::get_second(){
    return this->second;
}

template <typename T, typename U, typename K>
K& Triple<T, U, K>::get_third(){
    return this->third;
}

template <typename T, typename U, typename K>
const T& Triple<T, U, K>::get_first() const{
    return this->first;
}

template <typename T, typename U, typename K>
const U& Triple<T, U, K>::get_second() const{
    return this->second;
}

template <typename T, typename U, typename K>
const K& Triple<T, U, K>::get_third() const{
    return this->third;
}