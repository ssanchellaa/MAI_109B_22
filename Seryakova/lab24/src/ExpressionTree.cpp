#include "ExpressionTree.hpp"
#include <iostream>


   // Функция для проверки, является ли символ оператором
bool isOperator(char c) {
    return c == '+' || c == '*' || c == '^';
}

// Функция для создания дерева выражений из строки
TreeNode* buildExpressionTree(const std::string& expression) {
    std::stack<TreeNode*> st;

    std::istringstream iss(expression);
    std::string token;
    while (getline(iss, token, '+')) {
        TreeNode* node = new TreeNode(token);
        st.push(node);
    }

    while (st.size() > 1) {
        TreeNode* right = st.top();
        st.pop();
        TreeNode* left = st.top();
        st.pop();

        TreeNode* node = new TreeNode("+");
        node->left = left;
        node->right = right;
        st.push(node);
    }

    return st.top();
}

// Функция для обхода дерева и деления коэффициентов на k
void divideCoefficients(TreeNode* node, int k) {
    if (node == nullptr) {
        return;
    }

    if (node->left != nullptr) {
        divideCoefficients(node->left, k);
    }
    
    if (node->right != nullptr) {
        divideCoefficients(node->right, k);
    }

    if (isOperator(node->data[0])) {
        // Если узел содержит оператор, не делаем ничего
        return;
    } else {
        // Если узел содержит коэффициент и степень x, делим коэффициент на k и добавляем "*x^"
        size_t x_pos = node->data.find("x^");
        if (x_pos != std::string::npos) {
            int coefficient = stoi(node->data.substr(0, x_pos));
            int remainder = coefficient % k;
            if (remainder == 0) {
                coefficient /= k;
                node->data = std::to_string(coefficient) + "*x^" + node->data.substr(x_pos + 2);
            } else {
                node->data = std::to_string(coefficient) + "/" + std::to_string(k) + "*x^" + node->data.substr(x_pos + 2);
            }
        }
    }
}

// Функция для вывода выражения в инфиксной форме
void printInfix(TreeNode* node) {
    if (node == nullptr) {
        return;
    }

    if (isOperator(node->data[0])) {
        std::cout << "(";
    }

    printInfix(node->left);
    std::cout << node->data;
    printInfix(node->right);

    if (isOperator(node->data[0])) {
        std::cout << ")";
    }
}

// Функция для вывода выражения в постфиксной форме
void printPostfix(TreeNode* node) {
    if (node == nullptr) {
        return;
    }

    printPostfix(node->left);
    printPostfix(node->right);

    
    if (!isOperator(node->data[0])) {
        std::cout << node->data << " ";
    } else {
        std::cout << node->data;
    }
}