#ifndef EXPRESSION_TREE_HPP
   #define EXPRESSION_TREE_HPP

   #include <iostream>
   #include <stack>
   #include <string>
   #include <sstream>
   #include <cmath>

   struct TreeNode {
        std::string data;  // Операнд (коэффициент и степень x)
    	TreeNode* left;
    	TreeNode* right;

    	TreeNode(std::string d) : data(d), left(nullptr), right(nullptr) {}
   };

   bool isOperator(char c);
   TreeNode* buildExpressionTree(const std::string& expression);
   void divideCoefficients(TreeNode* node, int k);
   void printInfix(TreeNode* node);
   void printPostfix(TreeNode* node);

   #endif  // EXPRESSION_TREE_HPP