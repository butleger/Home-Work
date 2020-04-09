#include <iostream>
#include "Matrix.h"
using namespace std;


int main()
{
	Matrix m1(3,3);
//	m2.InputMatrix();
	m1.InputMatrix();
	Matrix m2(m1);
	m2.Reverse();
	cout << "Determinant is equal to " << m1.Determinant() << endl;
	cout << (m1*m2);
	//cout << "Reverse matrix is : \n" << m1;
	//Matrix m3 = m2 = m1;
	//cout << m1 * m2 ;
}

