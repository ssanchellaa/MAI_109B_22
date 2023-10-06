#ifndef MATRIXHPP
#define MATRIXHPP

#include "Vector.hpp"

template <typename T>
class Matrix {
private:
    size_t rows;
    size_t cols;
    Vector<Vector<T>> data;

public:
    Matrix(size_t rows, size_t cols);

    size_t numRows() const;
    size_t numCols() const;
    void setValue(size_t row, size_t col, T value);
    T getValue(size_t row, size_t col) const;
    Matrix<T> operator*(const Matrix<T>& other) const;
    bool isDiagonal() const;
};

#include "../src/Matrix.cpp"
#endif
