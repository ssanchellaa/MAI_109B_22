#include <iostream>
#include <string>
using namespace std;
 

#include "../include/BinaryTree.hpp"


int main() {
    BinaryTree bst;
    int choice;
    int maxLevel;
 
    do {
        cout << "Menu:\n";
        cout << "1. Add a node\n";
        cout << "2. Visualize Tree\n";
        cout << "3. Find Max Level\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
 
        switch (choice) {
            case 1:
                int value;
                cout << "Enter a value: ";
                cin >> value;
                bst.insert(value);
                break;
 
            case 2:
                cout << "Tree Visualization:\n";
                bst.visualizeTree();
                break;
 
            case 3:
                maxLevel = bst.findMaxLevel();
                cout << "Max Level: " << maxLevel << endl;
                break;
 
            case 4:
                cout << "Exiting...\n";
                break;
 
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
 
    return 0;
}
