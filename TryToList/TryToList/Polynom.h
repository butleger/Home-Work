#pragma once
#ifndef _H_POLYNOM_

#define _H_POLYNOM_
#include "MyList.h"
#include "Element.h"
struct Polynom : protected MyList<Element>//наследуем реализацию шаблона списка с вшитым Element
{
public :
	Polynom& operator*(Polynom & pol);//перегрузка умножения
	Polynom& operator+(Polynom & pol);//перегрузка сложения
protected:

};


#endif // !_H_POLYNOM_


