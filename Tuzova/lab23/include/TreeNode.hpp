#ifndef TREENODE_HPP_INCLUDED
#define TREENODE_HPP_INCLUDED

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

#endif

