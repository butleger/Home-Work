#pragma once
#ifndef _H_ELEMENT
#define _H_ELEMENT
#include <iostream>

struct Element//��������� 1 �������� ��������
{
public:
	Element();
	Element(double Coef, int Degree);//�����������
	bool Sign;//����, �����������, �������
	double Coef;
	int Degree;
private :
	friend std::ostream & operator<<(std::ostream & os, Element & el);//���������� ��������� ������
};
#endif // !_H_ELEMENT


