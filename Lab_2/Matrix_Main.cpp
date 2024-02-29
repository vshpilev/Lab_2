#include <iostream>
#include "Matrix.h"

int main() {
    Matrix matrix1(3, 3);
    Matrix matrix2(3, 3);

    matrix1.fillRandom();
    matrix2.fillRandom();

    std::cout << "Matrix 1:" << std::endl;
    std::cout << matrix1 << std::endl;

    std::cout << "Matrix 2:" << std::endl;
    std::cout << matrix2 << std::endl;

    Matrix matrixSum = matrix1 + matrix2;
    std::cout << "Matrix Sum:" << std::endl;
    std::cout << matrixSum << std::endl;

    Matrix matrixDiff = matrix1 - matrix2;
    std::cout << "Matrix Difference:" << std::endl;
    std::cout << matrixDiff << std::endl;

    Matrix matrixProduct = matrix1 * matrix2;
    std::cout << "Matrix Product:" << std::endl;
    std::cout << matrixProduct << std::endl;

    return 0;
}