#include "Matrix.h"
#include <cstdlib> // дл€ генерации случайных чисел

Matrix::Matrix(unsigned int m, unsigned int n) : m(m), n(n) {
    // ¬ыделение пам€ти дл€ двумерного массива
    data = new int* [m];
    for (unsigned int i = 0; i < m; ++i) {
        data[i] = new int[n];
    }
}

Matrix::~Matrix() {
    // ќсвобождение пам€ти из двумерного массива
    for (unsigned int i = 0; i < m; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

int*& Matrix::operator[](unsigned int index) {
    return data[index];
}

void Matrix::fillRandom() {
    for (unsigned int i = 0; i < m; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
            data[i][j] = rand() % 10; // генераци€ случайного числа от 0 до 9
        }
    }
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    for (unsigned int i = 0; i < matrix.m; ++i) {
        for (unsigned int j = 0; j < matrix.n; ++j) {
            os << matrix.data[i][j] << ' ';
        }
        os << std::endl;
    }
    return os;
}

Matrix operator+(const Matrix& matrix1, const Matrix& matrix2) {
    Matrix result(matrix1.m, matrix1.n);

    for (unsigned int i = 0; i < matrix1.m; ++i) {
        for (unsigned int j = 0; j < matrix1.n; ++j) {
            result.data[i][j] = matrix1.data[i][j] + matrix2.data[i][j];
        }
    }

    return result;
}

Matrix operator-(const Matrix& matrix1, const Matrix& matrix2) {
    Matrix result(matrix1.m, matrix1.n);

    for (unsigned int i = 0; i < matrix1.m; ++i) {
        for (unsigned int j = 0; j < matrix1.n; ++j) {
            result.data[i][j] = matrix1.data[i][j] - matrix2.data[i][j];
        }
    }

    return result;
}

Matrix operator*(const Matrix& matrix1, const Matrix& matrix2) {
    Matrix result(matrix1.m, matrix2.n);

    for (unsigned int i = 0; i < matrix1.m; ++i) {
        for (unsigned int j = 0; j < matrix2.n; ++j) {
            result.data[i][j] = 0;
            for (unsigned int k = 0; k < matrix1.n; ++k) {
                result.data[i][j] += matrix1.data[i][k] * matrix2.data[k][j];
            }
        }
    }

    return result;
}