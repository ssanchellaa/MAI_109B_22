#include "../include/Matrix.hpp"
#include <iostream>

Matrix::Matrix(): matrix_lines(0), matrix_columns(0){
    line_matrix.push_back(0);
    line_matrix.push_back(0);
}

Matrix::Matrix(size_t lines, size_t columns): matrix_lines(lines), matrix_columns(columns){
    line_matrix.push_back(0);
    line_matrix.push_back(0);
}

std::istream& operator>>(std::istream& is, Matrix& matrix){
    matrix.line_matrix.pop_back();
    size_t line, columns;
    int input_value;

    is >> line >> columns;

    matrix.matrix_lines = line;
    matrix.matrix_columns = columns;

    for (size_t i = 0; i != line; ++i){
        for (size_t j = 0; j != columns; ++j){
            is >> input_value;
            if (input_value != 0){
                if (matrix.line_matrix.back() == 0){
                    matrix.line_matrix.push_back(i + 1);
                }
                matrix.line_matrix.push_back(j + 1);
                matrix.line_matrix.push_back(input_value);
            }
        }

        if (matrix.line_matrix.back() != 0){
            matrix.line_matrix.push_back(0);
        }
    }
    matrix.line_matrix.push_back(0);

    return is;
}

std::ostream& operator<<(std::ostream& os, Matrix& matrix){
    for (size_t i = 0; i != matrix.line_matrix.size(); ++i){
        os << matrix.line_matrix[i] << " ";
    }

    return os;
}

Matrix Matrix::multiply(const Matrix& other){
    if (this->matrix_columns != other.matrix_lines){
        throw std::range_error("Columns not equal lines");
    }

    Matrix result(this->matrix_lines, other.matrix_columns);
    if (this->line_matrix.size() == 2 || other.line_matrix.size() == 2){
        return result;
    }

    for (size_t i = 0; i < matrix_lines; i++){
        for (size_t j = 0; j < other.matrix_columns; j++){
            int value = 0;
            for (size_t k = 0; k < matrix_columns; k++) {
                int element1 = line_matrix[i * matrix_columns + k];
                if (element1 == 0) {
                    break;
                }

                int rowIndex = line_matrix[(i + 1) * matrix_columns + k];
                int columnIndex = other.line_matrix[k * other.matrix_columns + j];

                if (columnIndex == 0 || rowIndex == 0){
                    break;
                }

                int element2 = other.line_matrix[rowIndex * other.matrix_columns + columnIndex];
                value += element1 * element2;
            }

            result.line_matrix.push_back(j);
            result.line_matrix.push_back(value);
        }

        result.line_matrix.push_back(0);
        result.line_matrix.push_back(0); // Добавляем признак конца строки в результирующей матрице
    }

    int line = result.line_matrix[1];
    for (size_t i = 0; i != result.line_matrix.size(); ++i){
        if (result.line_matrix[i] == 0 && i + 1 != result.line_matrix.size() - 1){
            line = result.line_matrix[i + 1];
            ++i;
        }
        
        if (result.line_matrix[i] != line){
            std::cout  << "Result matrix isn't diagonal" << std::endl;
            break;
        }
        ++i;
    }

    std::cout << "Result matrix is diagonal" << std::endl;
    return result;
}

void Matrix::print(){
    size_t line = 1, column = 1;
    for (size_t i = 0; i < line_matrix.size(); ++i) {

        if (!line_matrix[i]) {
            ++i;
            if (!line_matrix[i]) {
                while (line <= matrix_lines) {
                    while (column <= matrix_columns) {
                        column++;
                        std::cout << 0 << " ";
                    }
                    std::cout << '\n';
                    line++;
                    column = 1;
                }
                return;
            }
            while (line < line_matrix[i]) {
                while (column <= matrix_columns) {
                    column++;
                    std::cout << 0 << " ";
                }
                std::cout << '\n';
                line++;
                column = 1;
            }
        }
        else {
            while (column != line_matrix[i]) {
                column++;
                std::cout << 0 << " ";
            }
            ++i;
            column++;
            std::cout << line_matrix[i] << " ";
        }
    }
}