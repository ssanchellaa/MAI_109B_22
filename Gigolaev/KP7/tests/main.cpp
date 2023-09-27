#include "../include/Matrix.hpp"

int main(){
    
    Matrix matrix("Matrix.txt");

    matrix.print();
    matrix.transpose();
    std::cout << "after transpositioning " << std::endl;
    matrix.print();

    return 0;
}
