#include "../include/Node.hpp"

Node::Node() : Node('*', nullptr) {}
Node::Node(char _data) : Node(_data, nullptr) {}
Node::Node(char _data, Node* _next) : data(_data), next(_next) {}