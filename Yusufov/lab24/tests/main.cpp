#include "../include/Tree.hpp"

int main(){
    std::string str = "5+(1*15/(-4)+2)*3";

    Tree tree(str);
    tree.buildBinaryTree();
    tree.print();
    tree.swapInfStr();
    tree.print();
    tree.changeInfStr();

    return 0;
}