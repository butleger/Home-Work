#include <iostream>
#include "Matrix.h"
using namespace std;

//конструкторы и деструкторы
Matrix::Matrix(int string, int column) : StringSize(string), ColumnSize(column)
{
	if (string < 0 || column < 0)
	{
		cout << " bad sizes " << endl;
		return;
	}
	matrix = new double* [StringSize];
	for (int i = 0; i < StringSize; i++)
		matrix[i] = new double[ColumnSize];
	Nulling();
}

Matrix::Matrix(const Matrix& mat) : Matrix(mat.StringSize, mat.ColumnSize) 
{
	for (int i = 0; i < StringSize; i++)
		for (int j = 0; j < ColumnSize; j++)
			this->matrix[i][j] = mat.matrix[i][j];
}

Matrix::~Matrix()
{
	for (int i = 0; i < StringSize; i++)
		delete[] matrix[i];
	delete matrix;
}


//операторы
Matrix& Matrix::operator=(const Matrix& mat)
{
	if (mat.ColumnSize != this->ColumnSize || mat.StringSize != this->StringSize)
	{
		Matrix* m = new Matrix(mat.StringSize, mat.ColumnSize);
		cout << " bad matrix!" << endl;
		return *m;
	}
	for (int i = 0; i < this->StringSize; i++)
		for (int j = 0; j < this->ColumnSize; j++)
			this->matrix[i][j] = mat.matrix[i][j];
	return *this;
}

Matrix& operator+(const Matrix& m1, const Matrix& m2)
{
	if (m1.ColumnSize != m2.ColumnSize || m1.StringSize != m2.StringSize)
	{
		Matrix* m = new Matrix(m1.StringSize, m2.ColumnSize);
		cout << " bad matrix!" << endl;
		return *m;
	}
	Matrix* m = new Matrix(m1);
	for (int i = 0; i < m1.StringSize; i++)
		for (int j = 0; j < m1.ColumnSize; j++)
			m->matrix[i][j] += m2.matrix[i][j];
	return *m;
}

Matrix& operator-(const Matrix& m1, const Matrix& m2)
{
	if (m1.ColumnSize != m2.ColumnSize || m1.StringSize != m2.StringSize)
	{
		Matrix* m = new Matrix(m1.StringSize, m2.ColumnSize);
		cout << " bad matrix!" << endl;
		return *m;
	}
	Matrix* m = new Matrix(m1);
	for (int i = 0; i < m1.StringSize; i++)
		for (int j = 0; j < m1.ColumnSize; j++)
			m->matrix[i][j] -= m2.matrix[i][j];
	return *m;
}

ostream& operator<<(ostream& os, const Matrix& m2)
{
	for (int i = 0; i < m2.StringSize; i++) {
		for (int j = 0; j < m2.ColumnSize; j++)
			os << static_cast<double>(m2.matrix[i][j])<< " ";
		os << endl;
	}
	return os;
}

Matrix& operator*(const Matrix& m1, const Matrix& m2)
{
	if (m1.ColumnSize != m2.StringSize)
	{
		Matrix* m = new Matrix(m1.StringSize, m2.ColumnSize);
		cout << " bad matrix!" << endl;
		return *m;
	}

	Matrix* m = new Matrix(m1.StringSize, m2.ColumnSize);

	for (int i = 0; i < m1.StringSize; i++)
		for (int j = 0; j < m2.ColumnSize; j++)
			for (int k = 0; k < m1.ColumnSize; k++)
				m->matrix[i][j] += m1.matrix[i][k] * m2.matrix[k][j];
	return *m;
}
Matrix& Matrix::operator!()
{
	for (int i = 0; i < StringSize; i++)
		for (int j = 0; j < i; j++)
			swap(this->matrix[i][j], this->matrix[j][i]);
	return *this;
}

//функции
void Matrix::InputMatrix()
{
	for (int i = 0; i < StringSize; i++)
		for (int j = 0; j < ColumnSize; j++)
			cin >> matrix[i][j];
}

double Matrix::Determinant()
{
	if (this->StringSize != this->ColumnSize)
	{
		cout << "Bad Matrix for Determinant!\n";
	return 0;
	}
	return Determinant(matrix, StringSize);
	
}

int Matrix::getStrSize()
{
	return StringSize;
}

int Matrix::getColSize()
{
	return ColumnSize;
}

Matrix& Matrix::Reverse()
{
	if (ColumnSize != StringSize || this->Determinant() == 0 ) 
	{
		cout << " Non sqared matrix, cant do reverse!\n";
		Matrix* SuperMatrix = new Matrix(ColumnSize, ColumnSize);
		return *SuperMatrix;
	}

	double coef = 0.0;

	double ** sMatrix = new double*[StringSize];
	for (int i = 0; i < StringSize; i++)
		sMatrix[i] = new double[ColumnSize];
	for (int i = 0; i < StringSize; i++) {
		for (int j = 0; j < ColumnSize; j++)
			sMatrix[i][j] = 0.0;
		sMatrix[i][i] = 1.0;
	}



	for (int i = 0; i < StringSize; i++)
	{
		coef = matrix[i][i];
		for (int j = 0; j < ColumnSize; j++)
		{
			this->matrix[i][j] /= coef;
			sMatrix[i][j] = sMatrix[i][j]/ coef;
		}


		for (int i1 = i + 1; i1 < StringSize; i1++)
		{
			coef = matrix[i1][i];
			for (int j1 = 0; j1 < ColumnSize; j1++)
			{
				matrix[i1][j1] -= coef* matrix[i][j1];
			//	sMatrix[i1][j1] -= sMatrix[i1][i] * sMatrix[i][j1];
				sMatrix[i1][j1] -= coef * sMatrix[i][j1];
			}
		}
	}

	for (int i = StringSize - 1; i > -1 ; i--)
	{
		coef = matrix[i][i];
		for (int j = ColumnSize; j > -1 ; j--)
		{
			this->matrix[i][j] = this->matrix[i][j]/coef;
			sMatrix[i][j] /= coef;
		}

		for (int i1 = i - 1; i1 > -1 ; i1--)
		{
			coef = matrix[i1][i];
			for (int j1 = ColumnSize - 1; j1 > -1 ; j1--)
			{
				matrix[i1][j1] -= coef * matrix[i][j1];
				//sMatrix[i1][j1] -= sMatrix[i1][i] * sMatrix[i][j1];
				sMatrix[i1][j1] -= coef * sMatrix[i][j1];
			}
		}
	}

	Input(sMatrix);

	for (int i = 0; i < StringSize; i++)
		delete[] sMatrix[i];
	delete sMatrix;

	Matrix* m = new Matrix(*this);
	return *m;
}

//служебные поля
void Matrix::Nulling()
{
	for (int i = 0; i < StringSize; i++)
		for (int j = 0; j < ColumnSize; j++)
			matrix[i][j] = 0;
}

double Matrix::Determinant(double** matrix, int Size)
{
	if (Size == 2)
		return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];

	double result = 0.0;
	double ** sMatrix = new double* [Size - 1];
	for (int i = 0; i < Size - 1; i++)
		sMatrix[i] = new double[Size - 1];

	int I = 0, J = 0;

	for (int k = 0; k < Size; k++)
	{
		for (int i = 1; i < Size; i++) {
			for (int j = 0; j < Size; j++)
			{
				if (j == k)continue;
				sMatrix[I][J] = matrix[i][j];
				J++;
			}
			J = 0; I++;
		}
		result += (k%2 == 1 ? -1.0 : 1.0) * matrix[0][k] * Determinant(sMatrix, Size - 1);
		I = 0; J = 0;
	}

	for (int i = 0; i < Size - 1; i++)
		delete[] sMatrix[i];
	
	delete sMatrix;

	return result;
}

void Matrix::Input(double** matrix)
{
	for (int i = 0; i < StringSize; i++)
		for (int j = 0; j < ColumnSize; j++)
			this->matrix[i][j] = matrix[i][j];
}
