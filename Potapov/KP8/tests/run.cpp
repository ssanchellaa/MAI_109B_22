#include "../include/List.hpp"
#include <iostream>

int main(){
    List<int> list;

    list.push_back(14);
    list.push_back(1431);
    list.push_back(417);
    list.push_back(4141);
    list.push_front(532);
    list.push_front(411414);

    std::cout << list;

    list.task(3);
    std::cout << list;
}