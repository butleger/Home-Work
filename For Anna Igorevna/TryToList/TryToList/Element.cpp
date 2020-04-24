#pragma once
#ifndef _ELEMENT

#include "Element.h"
#define _ELEMENT_
using namespace std;

Element::Element() {};

Element::Element(double Coef, int Degree)//�����������
{
	this->Coef = Coef > 0 ? Coef : -1 * Coef;//������ ������ ������ ������������
	this->Degree = Degree;
	this->Sign = Coef > 0;//���� true �� + ����� -
}

std::ostream & operator<<(std::ostream & os, Element & el)
{
	if (el.Coef == 0)return os;
	if (el.Degree == 0) os << (el.Sign == 0 ? "- " : "");
	else os << (el.Sign == 0 ? "- " : "+ ") << el.Coef << "x^" << el.Degree;
	
	return os;
}
#endif // !_ELEMENT

