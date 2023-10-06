#include <gtest/gtest.h>

// Включаем заголовочный файл вашего кода
#include "ExpressionTree.hpp"

// Тест для функции isOperator
TEST(IsOperatorTest, TestValidOperators) {
    EXPECT_TRUE(isOperator('+'));
    EXPECT_TRUE(isOperator('*'));
    EXPECT_TRUE(isOperator('^'));
}

TEST(IsOperatorTest, TestInvalidOperators) {
    EXPECT_FALSE(isOperator('-'));
    EXPECT_FALSE(isOperator('/'));
    EXPECT_FALSE(isOperator('x'));
}

// Тест для функции buildExpressionTree
TEST(BuildExpressionTreeTest, TestBasicExpression) {
    std::string expression = "2*x^3+5*x^2+3*x^1+7";
    TreeNode* root = buildExpressionTree(expression);

    // Здесь можно написать дополнительные проверки
    // на корректность построения дерева
    // Например, проверить структуру дерева, убедиться,
    // что корректные узлы и операторы добавлены.
    
    // Простой тест на корректность корня дерева
    EXPECT_EQ(root->data, "+");
    EXPECT_EQ(root->left->data, "2*x^3");
    EXPECT_EQ(root->right->data, "+");

    // Освобождаем память, выделенную для дерева
    // Помните о необходимости написать деструктор для TreeNode, 
    // чтобы корректно освобождать память.
    delete root;
}

// Тест для функции divideCoefficients
TEST(DivideCoefficientsTest, TestDivisionByK) {
    TreeNode* root = new TreeNode("6*x^3");
    divideCoefficients(root, 2);

    // После деления на 2, значение должно быть "3*x^3"
    EXPECT_EQ(root->data, "3*x^3");

    // Освобождаем память, выделенную для узла
    delete root;
}

// Тест для функции printInfix
TEST(PrintInfixTest, TestInfixExpression) {
    TreeNode* root = new TreeNode("+");
    root->left = new TreeNode("2*x^2");
    root->right = new TreeNode("3*x^1");

    // Задаем буфер для вывода
    testing::internal::CaptureStdout();
    
    // Вызываем функцию печати в инфиксной форме
    printInfix(root);
    
    // Получаем вывод и проверяем его
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "(2*x^2)+3*x^1");

    // Освобождаем память, выделенную для узлов
    delete root->left;
    delete root->right;
    delete root;
}

TEST(PrintInfixTest, TestEmptyTree) {
    TreeNode* root = nullptr;

    testing::internal::CaptureStdout();
    printInfix(root);
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_EQ(output, "");
}

TEST(PrintInfixTest, TestSingleNode) {
    TreeNode* root = new TreeNode("2*x^3");

    testing::internal::CaptureStdout();
    printInfix(root);
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_EQ(output, "2*x^3");

    delete root;
}

// Тест для функции printPostfix
TEST(PrintPostfixTest, TestPostfixExpression) {
    TreeNode* root = new TreeNode("+");
    root->left = new TreeNode("2*x^2");
    root->right = new TreeNode("3*x^1");

    // Задаем буфер для вывода
    testing::internal::CaptureStdout();

    // Вызываем функцию печати в постфиксной форме
    printPostfix(root);

    // Получаем вывод и проверяем его
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "2*x^2 3*x^1 +");

    // Освобождаем память, выделенную для узлов
    delete root->left;
    delete root->right;
    delete root;
}

TEST(PrintPostfixTest, TestSingleNode) {
    TreeNode* root = new TreeNode("2*x^3");

    testing::internal::CaptureStdout();
    printPostfix(root);
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_EQ(output, "2*x^3");

    delete root;
}

TEST(PrintPostfixTest, TestComplexExpression) {
    TreeNode* root = new TreeNode("+");
    root->left = new TreeNode("2*x^2");
    root->right = new TreeNode("*");
    root->right->left = new TreeNode("3*x^1");
    root->right->right = new TreeNode("4*x^3");

    testing::internal::CaptureStdout();
    printPostfix(root);
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_EQ(output, "2*x^2 3*x^1 4*x^3 * +");

    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



