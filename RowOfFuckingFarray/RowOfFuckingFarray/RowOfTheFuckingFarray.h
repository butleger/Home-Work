#pragma once

#ifndef _ROW_OF_THE_FUCKING_FARRAY_H_
#define _ROW_OF_THE_FUCKING_FARRAY_H_
#include <iostream>
#include "List.h"
#include "Fraction.h"

class FarrayRow : protected MyList<Fraction>
{
protected :
	int Level;
    void Add_before();
    void Clear();
public :
	int getLevel();
    FarrayRow(Fraction first, Fraction second);
    void Show();
    void Increase();
};

#endif // !_ROW_OF_THE_FUCKING_FARRAY_H_

