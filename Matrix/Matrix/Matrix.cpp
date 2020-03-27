#include <iostream>
#include "Matrix.h"
using namespace std;


int main()
{
	try {
		Matrix m(2, 2), m1(2, 2);
		m.InputMatrix();
		m1.InputMatrix();
		m.OutputMatrix();
		Matrix m3 = (m * m1);
		m3.OutputMatrix();
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

