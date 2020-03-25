#include<iostream>
#include "MyList.h"
#include "Element.h"
#include "Polynom.h"
using namespace std;

template <class T>
void SwapMaxMin(MyList<T> list)//меняет местами максимум и минимум
{
    if (list.GetSize() == 0) throw exception("list is empty");

    size_t size = list.GetSize(), indexMax = 0, indexMin = 0;
    T max = list[indexMax];
    T min = list[indexMin];
    for (int i = 0; i < size; i++)
    {

        if (list[i] > max) { max = list[i]; indexMax = i; }
        if (list[i] < min) { min = list[i]; indexMin = i; }

    }

    list[indexMax] = min;
    list[indexMin] = max;
}

int main()
{
    MyList<Element> list;
    try {
        
        for (int i = 0; i < 10; i++)
            list.AddElement(Element(i,i), i);
        //SwapMaxMin(list);

        list.PrintAll();
        list.DeleteList();
    }
    catch (exception ex) { cout << ex.what() << endl; }
    catch (...) { cout << "undefined error"; }

    return 0;
}

