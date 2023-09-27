#ifndef MATRIXHPP
#define MATRIXHPP
#include "Vector.hpp"
#include <iostream>

class Matrix{
private:
    Vector<int> line_matrix;
    size_t matrix_lines;
    size_t matrix_columns;

public:
    Matrix();
    Matrix(size_t lines, size_t columns);

    friend std::istream& operator>>(std::istream& is, Matrix& matrix);
    friend std::ostream& operator<<(std::ostream& os, Matrix& matrix);

    Matrix multiply(const Matrix& other);
    void print();
};

#include "../src/Matrix.cpp"
#endif //MATRIXHPP