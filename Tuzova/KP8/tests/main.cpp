#include <iostream>
using namespace std;

#include "../include/List.hpp"

int main() {
    List list;
    list.insert('a');
    list.insert('b');
    list.insert('c');
    list.print();
    cout << "Length: " << list.length() << endl;
    list.removeBeforeAfter('b');
    list.print();
    cout << "Length: " << list.length() << endl;
}
