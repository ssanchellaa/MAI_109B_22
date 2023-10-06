#include "../include/Tree.hpp"
#include "../src/Tree.cpp"

namespace std {

} // namespace std;


int main() {
    Tree<int> bt;
    bt.insert(50);
    bt.insert(30);
    bt.insert(40);
    bt.insert(20);
    bt.insert(10);
    bt.insert(70);
    bt.insert(60);
    bt.insert(120);
    bt.insert(80);

    std::cout << "--------------------------------" << std::endl;
    std::cout << "tree 1: " << std::endl;
    bt.PrintResult(bt.get_root());
    std::cout << "--------------------------------" << std::endl;
    std::cout << bt;
    std::cout << "--------------------------------" << std::endl;
    bt.delete_node(50);
    std::cout << "tree 2: " << std::endl;
    bt.PrintResult(bt.get_root());
    std::cout << "--------------------------------" << std::endl;
    bt.print_tree();
    std::cout << "--------------------------------" << std::endl;
    bt.delete_node(30);
    std::cout << "tree 3: " << std::endl;
    bt.PrintResult(bt.get_root());
    std::cout << "--------------------------------" << std::endl;
    bt.print_tree();
    std::cout << "--------------------------------" << std::endl;
    bt.insert(24);
    std::cout << "tree 4: " << std::endl;
    bt.PrintResult(bt.get_root());
    std::cout << "--------------------------------" << std::endl;
    bt.print_tree();
    std::cout << "--------------------------------" << std::endl;
    bt.bypass();
    std::cout << "--------------------------------" << std::endl;

    return 0;
}
