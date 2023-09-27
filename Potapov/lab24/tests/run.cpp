#include "../include/Stack.hpp"
#include "../include/ExpressionTree.hpp"
#include <iostream>
#include <string>

int main(){
    ExpressionTree tree("a+b-(g*c)");
    tree.print_infix(tree.get_root());
    std::cout << std::endl;
    tree.print_postfix(tree.get_root());
    std::cout << std::endl;
    tree.print_tree(tree.get_root());
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    tree.task();
    tree.print_tree(tree.get_root());
}