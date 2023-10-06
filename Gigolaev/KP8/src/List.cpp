#include "../include/List.hpp"
List::List() : List(nullptr, new Node()) {}
List::List(Node* _head) : List(_head, new Node()) {}
List::List(Node* _head, Node* _barrier)
{
    head = _head;
    barrier = _barrier;
    if(head)
        head->next = barrier;
}
List::~List()
{
    Node* curr = head;
    while (curr != nullptr)
    {
        Node* nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }

}
bool List::Insert(Node* positionNode, Node* newNode)
{
    try
    {
        if(newNode == barrier || positionNode == barrier)
            throw "Node equals the barrier element. Udentified behaviour!";
        Node* current = head;
        do
        {
            if(current == positionNode)
            {
                newNode->next = positionNode->next;
                positionNode->next = newNode;
                return true;
            }
            current = current->next;
        }while(current != barrier);
        throw "There is no such node to insert after.";
    }
    catch(const char* message)
    {
        std::cerr << message << '\n';
        return false;
    }
}
bool List::Insert(Node *newNode)
{
    if(head == nullptr)
    {
        head = newNode;
        head->next = barrier;
        return true;
    }
    else
    {
        return Insert(head, newNode);
    }
}
bool List::Remove(Node* node)
{
    try
    {
        if(node == barrier)
            throw "Node equals the barrier element. Udentified behaviour!";
        Node* current = head->next;
        if(node == head)
        {
            delete head;
            if(current == barrier)
                head = nullptr;
            else
            {
                head = current;
            }
                
            return true;
        }

        do
        {
            if(current->next == node)
            {
                current->next = node->next;
                delete node;
                return true;
            }
            current = current->next;
        }while(current != barrier);
        throw "There is no such node to remove.";
    }
    catch(const char* message)
    {
        std::cerr << message << '\n';
        return false;
    }
}
bool List::ChangePlaces()
{
    size_t size = Size();
    if(size == 3)
        return true;
    if(size == 4)
    {
        Node* first = head;
        Node* second = first->next;
        Node* third = first->next->next;
        Node* last = first->next->next->next;
        first->next = third;
        third->next = second;
        second->next = last;
        return true;
    }
    if(size < 3)
        return false;
    Node* curr = head;
    Node* first = head;
    Node* prePreLast;
    do
    {
        if(curr->next->next->next == barrier)
        {
            prePreLast = curr;
            break;
        }
        curr = curr->next;
    }while(curr != barrier);
    Node* second = first->next;
    Node* third = first->next->next;
    Node* preLast = prePreLast->next;
    first->next = preLast;
    second->next = first->next->next;
    preLast->next = third;
    prePreLast->next = second;
    return true;
}
size_t List::Size() const
{
    size_t size = 0;
    if(head == nullptr)
        return size;
    Node* curr = head;
    do
    {
        ++size;
        curr = curr->next;
    }while(curr != barrier);
    return size;
}
std::ostream& operator<<(std::ostream& os, List& list) 
{
    if(list.head == nullptr)
        return os;
    Node* curr = list.head;
    do
    {
        os << curr->data << " ";
        curr = curr->next;
    }while(curr != list.barrier);
    os << "size: " << list.Size() << std::endl;
    return os;
}