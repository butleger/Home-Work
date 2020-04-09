#pragma once
#ifndef _H_MATRIX
#define _H_MATRIX
#include <iostream>
using namespace std;
class Matrix
{
public :
	//конструкторы и деструкторы
	Matrix(int string = 0, int column = 0);
	Matrix(const Matrix& mat);
	~Matrix();
	
	//операторы
	Matrix& operator=(const Matrix& m1);
	friend Matrix& operator+(const Matrix& m1, const Matrix& m2);
	friend Matrix& operator-(const Matrix& m1, const Matrix& m2);
	friend ostream& operator<<(ostream & os, const Matrix& m2);
	friend Matrix& operator*(const Matrix& m1, const Matrix& m2);
	Matrix& operator!();

	//функции
	void InputMatrix();
	double Determinant();
	int getStrSize();
	int getColSize();
	Matrix& Reverse();

protected :
	//поля
	int ColumnSize, StringSize;
	double** matrix;

	//служебные функции
	void Nulling();
	double Determinant(double ** matrix, int Size);
	void Input(double** matrix);
};

#endif // !_H_MATRIX


