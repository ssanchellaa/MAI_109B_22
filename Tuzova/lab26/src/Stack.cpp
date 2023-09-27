#include "../include/Stack.hpp"


Stack::Stack(int size){
    arr = new int[size];
    capacity = size;
    top = -1;
}

Stack::~Stack(){
    delete[] arr;
}

void Stack::push(int x){
    if (isFull()){
        cout << "Overflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    arr[++top] = x;
}

int Stack::pop(){
    if (isEmpty()){
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    return arr[top--];
}

int Stack::peek(){
    if (!isEmpty()){
        return arr[top];
    }
    else {
        exit(EXIT_FAILURE);
    }
}

int Stack::size(){
    return top + 1;
}

bool Stack::isEmpty(){
    return top == -1;
}

bool Stack::isFull(){
    return top == capacity - 1;
}

void Stack::print(){
    for (int i = top; i >= 0; i--)
        cout << arr[i] << " ";
    cout << endl;
}

void Stack::moveToFront(){
    if (top < 1) return; 
    int i = top;
    while (i > 0 && arr[i] < arr[i-1]) {
        swap(arr[i], arr[i-1]);
        i--;
    }
}

void insertionSort(Stack &s) {
    Stack tempStack;
    while (!s.isEmpty()){
        int temp = s.pop();
        while (!tempStack.isEmpty() && tempStack.peek() > temp){
            s.push(tempStack.pop());
        }
        tempStack.push(temp);
    }

    while (!tempStack.isEmpty()){
        s.push(tempStack.pop());
    }
}
