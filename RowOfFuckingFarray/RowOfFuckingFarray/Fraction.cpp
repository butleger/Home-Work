#include "Fraction.h"

Fraction::Fraction(int _numerator, int _denominator) :
	//	pair(_numerator, _denominator)
	first(_numerator),
	second(_denominator)
{}


ostream& operator<<(ostream& out, const Fraction& frac)
{
	out << frac.first << "/" << frac.second;
	return out;
}