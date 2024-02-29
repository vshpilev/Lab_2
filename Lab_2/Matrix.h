#pragma once
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix {
private:
    int** data; // ��������� ������
    unsigned int m; // ���������� �����
    unsigned int n; // ���������� ��������

public:
    Matrix(unsigned int m, unsigned int n); // �����������
    ~Matrix(); // ����������

    int*& operator[](unsigned int index); // �������� [] ������� �� �������

    void fillRandom(); // ����� ��������� ������ ���������� ���������� �� 0 �� 9

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix); // �������� ������ � �����
    friend Matrix operator+(const Matrix& matrix1, const Matrix& matrix2); // �������� +
    friend Matrix operator-(const Matrix& matrix1, const Matrix& matrix2); // �������� -
    friend Matrix operator*(const Matrix& matrix1, const Matrix& matrix2); // �������� *
};

#endif // MATRIX_H