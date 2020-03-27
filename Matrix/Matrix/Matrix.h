#pragma once
#ifndef _H_MATRIX
#define _H_MATRIX
#include <iostream>

class Matrix
{
public:

    // конструктор создания матрицы

    Matrix();

    Matrix(int, int);

    // конструктор копирования

    Matrix(const Matrix&);

    // деструктор

    ~Matrix();

    // метод получения размера матрицы

    int GetString();
    int GetColumn();

    // перегруженные операторы
   // double operator[](int);

    friend Matrix operator+(Matrix&, Matrix&);

    friend Matrix operator*(Matrix&, Matrix&);

    Matrix operator=(Matrix&);

    friend Matrix operator!(Matrix&);

    void InputMatrix();// метод ввода матрицы

    void OutputMatrix();// метод вывода матрицы

    double Determinant();

private :

    double** matrix;
    int column, string;

   double Determinant(double** matrix, int strSize, int colSize);
    void Nulling();

};


#endif // !_H_MATRIX


