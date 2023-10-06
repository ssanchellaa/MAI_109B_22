#include "ExpressionTree.hpp"

  
       int main() {
    std::string input;
    int k;

    std::cout << "Введите многочлен в инфиксной форме: ";
    std::cin >> input;

    std::cout << "Введите число k: ";
    std::cin >> k;

    TreeNode* root = buildExpressionTree(input);
    divideCoefficients(root, k);

    std::cout << "Многочлен после деления на " << k << " в инфиксной форме: ";
    printInfix(root);
    std::cout << std::endl;

    std::cout << "Многочлен после деления на " << k << " в постфиксной форме: ";
    printPostfix(root);
    std::cout << std::endl;

    return 0;
}