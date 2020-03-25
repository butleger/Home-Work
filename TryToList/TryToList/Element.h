#pragma once
#ifndef _H_ELEMENT
#define _H_ELEMENT
#include <iostream>

struct Element//структура 1 элемента полинома
{
public:
	Element();
	Element(double Coef, int Degree);//конструктор
	bool Sign;//знак, коэффициент, степень
	double Coef;
	int Degree;
private :
	friend std::ostream & operator<<(std::ostream & os, Element & el);//перегрузка оператора вывода
};
#endif // !_H_ELEMENT


