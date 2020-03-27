#pragma once
#ifndef _H_MATRIX
#define _H_MATRIX
#include <iostream>

class Matrix
{
public:

    // ����������� �������� �������

    Matrix();

    Matrix(int, int);

    // ����������� �����������

    Matrix(const Matrix&);

    // ����������

    ~Matrix();

    // ����� ��������� ������� �������

    int GetString();
    int GetColumn();

    // ������������� ���������
   // double operator[](int);

    friend Matrix operator+(Matrix&, Matrix&);

    friend Matrix operator*(Matrix&, Matrix&);

    Matrix operator=(Matrix&);

    friend Matrix operator!(Matrix&);

    void InputMatrix();// ����� ����� �������

    void OutputMatrix();// ����� ������ �������

    double Determinant();

private :

    double** matrix;
    int column, string;

   double Determinant(double** matrix, int strSize, int colSize);
    void Nulling();

};


#endif // !_H_MATRIX


