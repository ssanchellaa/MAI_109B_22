#include <iostream>
#include <cstdlib>
#include "../include/Stack.hpp"

using namespace std;


int main(){
    Stack s;
    s.push(3);
    s.push(1);
    s.push(2);
    s.print();
    insertionSort(s);
    s.print(); // вывод: 1 2 3
    return 0;
}
