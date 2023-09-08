#include "../include/List.hpp"
#include <iostream>

int main(){
    List<int> list = {4, 2, 3, 1, 7, 5};
    list.bubble_sort();
    std::cout << list;

    return 0; 
}