#include "../include/Tree.hpp"

Tree::Tree(const std::string& infStr) : infStr(infStr){}


bool Tree::isOperator(char simbol) const{
    return (simbol == '-' || simbol == '+' || simbol == '*' || simbol == '/' || simbol == '^');
}

size_t Tree::getPriority(char simbol) const{
    switch(simbol){
        case('-'): return 1;
        case('+'): return 1;
        case('*'): return 2;
        case('/'): return 2;
        case('^'): return 3;
        case('~'): return 4;
    }
    return 0;
}

void Tree::pasteOperandNode(Vector<Node<std::string>*>& nodes, char simbol){

    std::string str = ""; str += simbol;
    Node<std::string>* newNode = new Node<std::string>(str);

    if(simbol == '~'){
        newNode->right = nodes.back();
        nodes.back() = newNode;
    }
    else{
        newNode->right = nodes.back();
        nodes.pop_back();
        newNode->left = nodes.back();
        nodes.back() = newNode;
    }

}

void Tree::buildBinaryTree(){
    Vector<Node<std::string>*> nodes;
    Vector<char> operators;

    std::string digit = "";

    for(size_t currentChar = 0; currentChar < this->infStr.size(); ++currentChar){

        char simbol = this->infStr[currentChar];
        if(!isOperator(simbol) && simbol != '(' && simbol != ')'){
            digit += simbol;
        }
        else{
            if(digit != "") {
                nodes.push_back(new Node<std::string>(digit));
                digit = "";
            }

            if(isOperator(simbol)){

                if(simbol == '-') {
                    if(currentChar == 0){
                        simbol = '~';
                    }
                    if(this->infStr[currentChar - 1] == '('){
                        simbol = '~';
                    }
                }

                while(!operators.empty() && getPriority(operators.back()) >= getPriority(simbol)){
                
                    pasteOperandNode(nodes, operators.back());
                    operators.pop_back();

                }
                operators.push_back(simbol);
            }
            else if(simbol == ')'){
                while(operators.back() != '('){

                    pasteOperandNode(nodes, operators.back());
                    operators.pop_back();

                }
                operators.pop_back();
            }
            else operators.push_back(simbol);

        }
    }

    if(digit != ""){
        nodes.push_back(new Node<std::string>(digit));
    }

    while(!operators.empty()){

        pasteOperandNode(nodes, operators.back());
        operators.pop_back();

    }

    this->root = nodes.back();

}

void Tree::swapInfStr(Node<std::string>* node){
    if(node == nullptr){
        node = this->root;
    }

    if(node->data == "+" || node->data == "*"){
        std::swap(node->left, node->right);
    }

    if(node->left != nullptr){
        swapInfStr(node->left);
    }
    if(node->right != nullptr){
        swapInfStr(node->right);
    }

}

void Tree::print(Node<std::string>* node, size_t deapth) const{
    if(node == nullptr){
        node = this->root;
    }

    if(node->right != nullptr){
        print(node->right, deapth + 1);
    }

    for(size_t i = 0; i < deapth; ++i){
        std::cout << '\t';
    }
    std::cout << node->data << std::endl;

    if(node->left != nullptr){
        print(node->left, deapth + 1);
    }
}

void Tree::clear(Node<std::string>* node){
    if(node == nullptr){
        node = this->root;
    }

    if(node->left != nullptr){
        clear(node->left);
    }
    if(node->right != nullptr){
        clear(node->right);
    }
    delete node;
}

void Tree::changeInfStr(Node<std::string>* node){
    static std::string changedInfStr = "";
    if(node == nullptr){
        node = this->root;
    }
    
    if(node->data == "~"){
        changedInfStr += '(';
    }
    if(node->left != nullptr){
        changedInfStr += '(';
        changeInfStr(node->left);
    }
    changedInfStr += node->data;
    if(node->right != nullptr){
        changeInfStr(node->right);
        changedInfStr += ')';
    }
   
    if(node == this->root){
        std::cout << this->infStr << std::endl;
        this->infStr = changedInfStr;
        std::cout << this->infStr << std::endl;
    }

}

Tree::~Tree(){
    clear();
}