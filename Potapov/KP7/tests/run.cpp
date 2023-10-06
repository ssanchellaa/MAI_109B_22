#include "../include/Matrix.hpp"
#include <iostream>

int main(){
    Matrix mat_a, mat_b;
    std::cin >> mat_a;
    std::cout << mat_a;
    std::cin >> mat_b;
    std::cout << mat_b;

    Matrix mat_c = mat_a.multiply(mat_b);
    mat_c.print();

    return 0;
}