#pragma once
#ifndef _H_MY_LIST
#define _H_MY_LIST
#include <iostream>

using namespace std;

template <class T>
struct MyList//структура списка
{
public:
    T Data;//поле данных

    virtual void PrintAll();//рекурсивная функция печати всех элементов
    MyList();//конструктор по умолчанию
    void DeleteList();//рекурсивная функция удаляющая весь список
    virtual void AddElement(T Data, int index);//рекурсивная функция добавляющая элемент
    void DeleteElement(int index);//рекурсивная функция удялющая элемент
    T & operator[](int);//перегрузка оператора [] для получения элементов
    int GetSize();//отдает размер списка
protected:
    MyList(T Data, MyList* Next = nullptr);//служебный конструктор
    bool isRoot;//проверяет является ли этот узел точкой входа(первым узлом, созданным в main)
    MyList<T>* Next;//хранит следующий элемент
};

template <class T>
MyList<T>::MyList()//паблик конструктор, также показывает что этот элемент - первый в списке 
{
    this->Next = nullptr;
    this->isRoot = true;
}

template <class T>
MyList<T>::MyList(T Data, MyList* Next)//скрытый конструктор
{
    isRoot = false;//показывает что это не первый элемент списка
    this->Next = Next;
    this->Data = Data;
}

template <class T>
void MyList<T>::DeleteList()//реализация рекурсивной функции удаления
{
    if (this == nullptr)return;//если элемент не существует выходим
    this->Next->DeleteList();//сначала удаляем следующие элементы
    if (!isRoot) delete this;//потом себя
}

template <class T>
void MyList<T>::AddElement(T Data, int index)//реализация рекурсивной функции добавления элемента
{
    if (index < 0) exception("bad index");
    if (index == 0) this->Next = new MyList(Data, this->Next);//если индекс равен 0 то надо добавлять на эту позицию
    else if (this == nullptr)throw exception("segmenttion fold)))))");//если выходим за пределы списка - эксепшин
    else this->Next->AddElement(Data, index - 1);//если все норм просто передаем дальше
}

template <class T>
void MyList<T>::PrintAll()//реализация рекурсивной функции печати всех элементов
{
    if (this == nullptr)return;//если это конец то выходим
    else if (!isRoot)//если не 1 элемент, то печатаем
    {
        cout << this->Data << " ";
    }
    if ( this->Next != nullptr )
    this->Next->PrintAll();//и вызываем эту функцию у следующего элемента
}

template <class T>
T & MyList<T>::operator[](int index)//рекурсивная реализация оператора []
{
    if (index < 0) exception("bad index");
    //если элемент не существует то эксепшн или если это первый элемент и следующий не существует
    if (this == nullptr || (isRoot && this->Next == nullptr)) throw exception("out from list in []");
    if (isRoot) return this->Next->operator[](index);//если первый элемент то просто идем дальше
    if (index == 0) return this->Data;//если нужно отдать этот элемент то отдаем
    else return this->Next->operator[](index - 1);//если нужен 1 из следующих элементов идем дальше
}

template <class T>
int MyList<T>::GetSize()//функция получения размера
{
    if (isRoot && this->Next == nullptr) return 0;//если есть только базовый элемент размер 0
    if (isRoot) return this->Next->GetSize();// иначе дергаем точку входа
    else if (this->Next == nullptr) return 1;//если это конец возвращаем 1;
    else return this->Next->GetSize() + 1;//если не конец считаем сколько дальше и учитываем себя
}

template <class T>
void MyList<T>::DeleteElement(int index)
{
    if (isRoot)//если это 1 элемент обрабатываются все сложные ситуации
    {
        if (index < 0) throw exception("bad index");
        if (index == 0 && this->Next != nullptr)//если нужно удалить 1 элемент
        {
            MyList* temp = this->Next->Next;
            delete this->Next;
            this->Next = temp;
            return;
        }

        if (index == 0 && this->Next == nullptr) throw exception("bad index");//если не существует 1 элемента
    }


    if (index != 0) this->Next->DeleteElement(index - 1);//если еще не конец идем дальше
    else
    {
        MyList* temp = this->Next->Next;//если это нужный элемент удаляем его
        delete this->Next;
        this->Next = temp;
        return;
    }
}
#endif // !_H_MY_LIST



