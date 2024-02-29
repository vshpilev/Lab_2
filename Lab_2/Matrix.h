#pragma once
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix {
private:
    int** data; // двумерный массив
    unsigned int m; // количество строк
    unsigned int n; // количество столбцов

public:
    Matrix(unsigned int m, unsigned int n); // конструктор
    ~Matrix(); // деструктор

    int*& operator[](unsigned int index); // оператор [] доступа по индексу

    void fillRandom(); // метод заполняет массив случайными значениями от 0 до 9

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix); // оператор вывода в поток
    friend Matrix operator+(const Matrix& matrix1, const Matrix& matrix2); // оператор +
    friend Matrix operator-(const Matrix& matrix1, const Matrix& matrix2); // оператор -
    friend Matrix operator*(const Matrix& matrix1, const Matrix& matrix2); // оператор *
};

#endif // MATRIX_H