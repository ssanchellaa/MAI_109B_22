#ifndef BINARYTREE_HPP_INCLUDED
#define BINARYTREE_HPP_INCLUDED

#include "../include/TreeNode.hpp"

#include <iostream>
#include <string>
 
class BinaryTree {
private:
    TreeNode* root;
 
public:
    BinaryTree();
 
    void insert(int value); 
 
    void visualizeTree(); 
 
    int findMaxLevel(); 
 
private:
    TreeNode* insertRec(TreeNode* node, int value); 
 
    void visualizeTreeRec(TreeNode* node, int depth);
 
    void findMaxLevelRec(TreeNode* node, int level, int& maxLevel, int& maxCount); 
};
 
#include "../src/BinaryTree.cpp"

#endif

