#pragma once
#ifndef _H_POLYNOM_

#define _H_POLYNOM_
#include "MyList.h"
#include "Element.h"
struct Polynom : protected MyList<Element>//��������� ���������� ������� ������ � ������ Element
{
public :
	Polynom& operator*(Polynom & pol);//���������� ���������
	Polynom& operator+(Polynom & pol);//���������� ��������
protected:

};


#endif // !_H_POLYNOM_


