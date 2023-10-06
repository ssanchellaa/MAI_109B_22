#include "../include/ExpressionTree.hpp"
#include "../include/Stack.hpp"

ExpressionTree::ExpressionTree(): root(nullptr){}

ExpressionTree::ExpressionTree(const std::string& expression){
    std::string postfix = do_postfix(expression);
    root = create_tree(postfix);
}

ExpressionTree::~ExpressionTree(){
    delete_tree(this->root);
}

void ExpressionTree::delete_tree(Node* root){
    if (root == nullptr) return;

    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
    root = nullptr;
}

Node* ExpressionTree::get_root() const{
    return this->root;
}

uint8_t ExpressionTree::get_priority(const char oper) const{
    switch (oper){
        case '+': 
            return 1;
        case '-':
            return 1;
        case '*': 
            return 2;
        case '/':
            return 2;
        case '^':
            return 3;
        case '~':
            return 4;
    }
    return 0;
}

bool ExpressionTree::is_operator(const char symbol) const{
    return (symbol == '-' || symbol == '+' || symbol == '*' || symbol == '/' || symbol == '^');
}

std::string ExpressionTree::do_postfix(const std::string& expression){
    std::string postfix = "";
    Stack<char> stack;

    for (size_t i = 0; i != expression.length(); ++i){
        char c = expression[i];

        if (!is_operator(c) && c != '(' && c != ')'){
            postfix += c;
        } else if (c == '('){
            stack.push(c);
        } else if (c == ')'){
            while (stack.top() != '('){
                postfix += stack.top();
                stack.pop();
            }
            stack.pop();
        } else{
            if (c == '-' && expression[i - 1] == '(') c = '~';

            while (!stack.empty() && (get_priority(stack.top()) >= get_priority(c))){
                postfix += stack.top();
                stack.pop();
            }
            stack.push(c);
        }
    }

    while (!stack.empty()){
        postfix += stack.top();
        stack.pop();
    }
    return postfix;
}

Node* ExpressionTree::create_tree(const std::string& postfix){
    if (postfix.length() == 0) return nullptr;

    Stack<Node*> stack;
    for (char c: postfix){
        if (c == '~'){
            Node* node_x = stack.top();
            stack.pop();
            Node* node = new Node('-', nullptr, node_x);
            stack.push(node);
        } else if (is_operator(c)){
            Node* node_x = stack.top();
            stack.pop();

            Node* node_y = stack.top();
            stack.pop();

            Node* node = new Node(c, node_y, node_x);
            stack.push(node);
        } else{
            stack.push(new Node(c));
        }
    }
    return stack.top();
}

void ExpressionTree::task(){
    root = task(root);
}

Node* ExpressionTree::task(Node* root){
    if (root == nullptr) return root;

    if (root->data == '-' && root->left != nullptr){
        root->data = '+';
        root->right = new Node('-', nullptr, root->right);
        return root;
    }

    root->left = task(root->left);
    root->right = task(root->right);

    return root;
}


void ExpressionTree::print_postfix(Node* root) const{
    if (root == nullptr) return;

    print_postfix(root->left);
    print_postfix(root->right);
    std::cout << root->data;
}

void ExpressionTree::print_infix(Node* root) const{
    if (root == nullptr) return;

    if (is_operator(root->data)){
        std::cout << '(';
    }

    print_infix(root->left);
    std::cout << root->data;
    print_infix(root->right);

    if (is_operator(root->data)){
        std::cout << ')';
    }
}

void ExpressionTree::print_tree(Node* root, const uint64_t height) const{
    if (root != nullptr){
        print_tree(root->right, height + 1);
        for (size_t i = 0; i < height; ++i){
            std::cout << "\t";
        }
        std::cout << root->data << "\n";
        print_tree(root->left, height + 1);
    }
}