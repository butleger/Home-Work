#include "Matrix.h"
#include <cmath>
#include <iostream>
using namespace std;

// конструктор создания матрицы

Matrix::Matrix()
{
	string = 0;
	column = 0;
	matrix = nullptr;
}

Matrix::Matrix(int string, int column)
{
	this->string = string;
	this->column = column;
	matrix = new double* [string];
	for (int i = 0; i < string; i++)
		matrix[i] = new double[column];
	this->Nulling();
}

// конструктор копирования

Matrix::Matrix(const Matrix& mat)
{
	this->string = mat.string;
	this->column = mat.column;
	matrix = new double* [string];
	for (int i = 0; i < string; i++)
		matrix[i] = new double[column];

	for (int i = 0; i < this->string; i++)
		for (int j = 0; j < this->column; j++)
			this->matrix[i][j] = mat.matrix[i][j];
}

// деструктор

Matrix::~Matrix()
{
	for (int i = 0; i < this->string; i++)
		delete[] matrix[i];
	delete[] matrix;
}

// метод получения размера матрицы

int Matrix::GetString()
{
	return string;
}

int Matrix::GetColumn()
{
	return column;
}

// перегруженные операторы

Matrix operator+(Matrix& first, Matrix& second)
{
	if (first.column != second.column || first.string != second.column) throw exception("bad matrix for sum");

	Matrix* temp = new Matrix(first.string,first.column);
	temp->Nulling();

	for (int i = 0; i < temp->string; i++)
		for (int j = 0; j < temp->column; j++)
			temp->matrix[i][j] = first.matrix[i][j] + second.matrix[i][j];
	return (*temp);
}

Matrix operator*(Matrix& first, Matrix& second)
{
	if (first.string != second.column ) throw exception("bad matrix for multy");

	Matrix* temp = new Matrix(second.string, first.column);
	temp->Nulling();

	for (int i = 0; i < temp->string; i++)
		for (int j = 0; j < temp->column; j++)
			for (int k = 0; k < first.column; k++)
				temp->matrix[i][j] += first.matrix[i][k] * second.matrix[k][j];

	return (*temp);
}

Matrix Matrix::operator=(Matrix& mat)
{
	if (this->string != mat.string || this->column != mat.column ) throw exception("bad matrix for equality");

	Matrix* temp = new Matrix(mat.string, mat.column);
	temp->Nulling();

	for (int i = 0; i < this->string; i++)
		for (int j = 0; j < this->column; j++)
			this->matrix[i][j] = mat.matrix[i][j];

	return (*temp);
}

Matrix operator!(Matrix& mat)
{
	for (int i = 0; i < mat.string; i++)
		for (int j = 0; j < i; j++)
			swap(mat.matrix[i][j], mat.matrix[j][i]);
	return mat;
}

void Matrix::InputMatrix()// метод ввода матрицы
{
	for (int i = 0; i < this->string; i++)
		for (int j = 0; j < this->column; j++)
			cin >> this->matrix[i][j];
}
void Matrix::OutputMatrix()// метод вывода матрицы
{
	for (int i = 0; i < this->string; i++) {
		for (int j = 0; j < this->column; j++)
			cout << this->matrix[i][j] << " ";
		cout << endl;
	}
}
double Matrix::Determinant()
{
	return Determinant(this->matrix, this->string, this->column);
}

double Matrix::Determinant(double** matrix, int strSize, int colSize)
{
	if (strSize != colSize) throw exception("Cant compute determinant of non-square matrix");

	if (strSize == 2) return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];

	double determinant = 0.0;
	int J = 0;
	double** temp = new double*[strSize - 1];
	for (int i = 0; i < strSize - 1; i++)
	{
		temp[i] = new double[colSize - 1];
		for (int j = 0; j < colSize - 1; j++)
			temp[i][j] = 0;
	}

	for (int j = 0; j < colSize; j++)
	{
		for (int i = 1; i < strSize; i++) 
		{
			for (int k = 0; k < colSize; k++)
			{
				if (k == j) continue;
				temp[i - 1][J] = matrix[i][k];
				determinant += matrix[0][j] * (j % 2 == 0 ? -1 : 1) * Determinant(temp, strSize - 1, colSize - 1);
				J++;
			}
			J = 0;
		}
		for (int i = i = 0; i < strSize - 1; i++)
			for (int j = 0; j < colSize - 1; j++)
				temp[i][j] = 0;

	}
	return determinant;

}

void Matrix::Nulling()
{
	for (int i = 0; i < this->string; i++)
		for (int j = 0; j < this->column; j++)
			this->matrix[i][j] = 0;
}
