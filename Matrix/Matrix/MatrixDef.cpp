#include "Matrix.h"
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

//double Matrix::Determinant(double** matrix, int strSize, int colSize)
//{
//	void getMatrixWithoutRowAndCol(int** matrix, int size, int row, int col, int** newMatrix) {
//		int offsetRow = 0;
//		int offsetCol = 0;
//		for (int i = 0; i < size - 1; i++) {
//			if (i == row) {
//				offsetRow = 1;
//			}
//
//			offsetCol = 0;
//			for (int j = 0; j < size - 1; j++) {
//				if (j == col) {
//					offsetCol = 1;
//				}
//
//				newMatrix[i][j] = matrix[i + offsetRow][j + offsetCol];
//			}
//		}
//	}
//}

void Matrix::Nulling()
{
	for (int i = 0; i < this->string; i++)
		for (int j = 0; j < this->column; j++)
			this->matrix[i][j] = 0;
}
