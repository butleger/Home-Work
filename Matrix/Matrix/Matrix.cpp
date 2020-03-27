#include <iostream>
#include "Matrix.h"
using namespace std;


int main()
{
	try {
		Matrix m(3, 3), m1(2, 2);
		m.InputMatrix();
		cout << m.Determinant();
	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
	}
	catch (...)
	{
		cout << "Undefined exception" << endl;
	}
}

