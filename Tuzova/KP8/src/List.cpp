
#include "../include/List.hpp"

    List::List() : head(nullptr) {}

    void List::insert(char data) {
        Node* newNode = new Node{data, nullptr, nullptr};
        if (head == nullptr) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev->next = newNode;
            head->prev = newNode;
        }
    }

    void List::remove(char data) {
        if (head == nullptr) return;

        Node* current = head;
        do {
            if (current->data == data) {
                if (current == head) {
                    if (head->next == head) {
                        delete head;
                        head = nullptr;
                        return;
                    } else {
                        head->prev->next = head->next;
                        head->next->prev = head->prev;
                        Node* temp = head;
                        head = head->next;
                        delete temp;
                    }
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    delete current;
                }
                return;
            }
            current = current->next;
        } while (current != head);
    }

    int List::length() {
        if (head == nullptr) return 0;

        int count = 0;
        Node* current = head;
        do {
            count++;
            current = current->next;
        } while (current != head);
        return count;
    }

    void List::print() {
        if (head == nullptr) return;

        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }

    void List::removeBeforeAfter(char data) {
    if (head == nullptr) return;

    Node* current = head;
    do {
        if (current->data == data) {
            Node* temp = current->next;
            while (temp != current) {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                Node* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
            head = current;
            head->next = head;
            head->prev = head;
            return;
        }
        current = current->next;
    } while (current != head);
}

    List::~List() {
    	removeBeforeAfter(head->data);
    	delete head;
    }
    
    
    
    
    
    
    
    
  

