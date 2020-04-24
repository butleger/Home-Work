#pragma once

#ifndef _FRACTION_H_
#define _FRACTION_H_
#include <iostream>
#include <utility>
using namespace std;

struct Fraction : public pair<int, int>
{
	Fraction(int _numerator, int _denuminator);
	int first;
	int second;
};



#endif // !_FRACTION_H_
