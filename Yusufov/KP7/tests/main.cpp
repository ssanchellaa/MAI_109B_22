#include <iostream>
#include "../include/Matrix.hpp"

int main() {
    size_t rows1, cols1, rows2, cols2;

    // Ввод размеров матриц 1 и 2
    std::cout << "Enter number of rows for matrix 1: ";
    std::cin >> rows1;

    std::cout << "Enter number of columns for matrix 1: ";
    std::cin >> cols1;

    std::cout << "Enter number of rows for matrix 2: ";
    std::cin >> rows2;

    std::cout << "Enter number of columns for matrix 2: ";
    std::cin >> cols2;

    if (cols1 != rows2) {
        std::cout << "Matrices cannot be multiplied due to mismatched dimensions." << std::endl;
        return 1;
    }

    Matrix<double> matrix1(rows1, cols1);
    Matrix<double> matrix2(rows2, cols2);

    // Ввод значений для матрицы 1
    std::cout << "Enter values for matrix 1:" << std::endl;
    for (size_t i = 0; i < rows1; ++i) {
        for (size_t j = 0; j < cols1; ++j) {
            double value;
            std::cin >> value;
            matrix1.setValue(i, j, value);
        }
    }

    // Ввод значений для матрицы 2
    std::cout << "Enter values for matrix 2:" << std::endl;
    for (size_t i = 0; i < rows2; ++i) {
        for (size_t j = 0; j < cols2; ++j) {
            double value;
            std::cin >> value;
            matrix2.setValue(i, j, value);
        }
    }

    Matrix<double> result = matrix1 * matrix2;

    std::cout << "Matrix multiplication result:" << std::endl;
    for (size_t i = 0; i < result.numRows(); ++i) {
        for (size_t j = 0; j < result.numCols(); ++j) {
            std::cout << result.getValue(i, j) << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Is the result matrix diagonal? " << (result.isDiagonal() ? "Yes" : "No") << std::endl;

    return 0;
}
