#include "../include/Matrix.hpp"

template <typename T>
Matrix<T>::Matrix(size_t rows, size_t cols) : rows(rows), cols(cols), data(rows, Vector<T>(cols)) {}

template <typename T>
size_t Matrix<T>::numRows() const {
    return rows;
}

template <typename T>
size_t Matrix<T>::numCols() const {
    return cols;
}

template <typename T>
void Matrix<T>::setValue(size_t row, size_t col, T value) {
    data[row][col] = value;
}

template <typename T>
T Matrix<T>::getValue(size_t row, size_t col) const {
    return data[row][col];
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) const {
    if (cols != other.rows) {
        throw std::invalid_argument("Matrix dimensions do not match for multiplication");
    }

    Matrix<T> result(rows, other.cols);

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < other.cols; ++j) {
            for (size_t k = 0; k < cols; ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }

    return result;
}

template <typename T>
bool Matrix<T>::isDiagonal() const {
    if (rows != cols) {
        return false;
    }

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            if (i != j && data[i][j] != 0) {
                return false;
            }
        }
    }

    return true;
}
