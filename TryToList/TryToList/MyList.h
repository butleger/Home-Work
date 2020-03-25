#pragma once
#ifndef _H_MY_LIST
#define _H_MY_LIST
#include <iostream>

using namespace std;

template <class T>
struct MyList//��������� ������
{
public:
    T Data;//���� ������

    virtual void PrintAll();//����������� ������� ������ ���� ���������
    MyList();//����������� �� ���������
    void DeleteList();//����������� ������� ��������� ���� ������
    virtual void AddElement(T Data, int index);//����������� ������� ����������� �������
    void DeleteElement(int index);//����������� ������� �������� �������
    T & operator[](int);//���������� ��������� [] ��� ��������� ���������
    int GetSize();//������ ������ ������
protected:
    MyList(T Data, MyList* Next = nullptr);//��������� �����������
    bool isRoot;//��������� �������� �� ���� ���� ������ �����(������ �����, ��������� � main)
    MyList<T>* Next;//������ ��������� �������
};

template <class T>
MyList<T>::MyList()//������ �����������, ����� ���������� ��� ���� ������� - ������ � ������ 
{
    this->Next = nullptr;
    this->isRoot = true;
}

template <class T>
MyList<T>::MyList(T Data, MyList* Next)//������� �����������
{
    isRoot = false;//���������� ��� ��� �� ������ ������� ������
    this->Next = Next;
    this->Data = Data;
}

template <class T>
void MyList<T>::DeleteList()//���������� ����������� ������� ��������
{
    if (this == nullptr)return;//���� ������� �� ���������� �������
    this->Next->DeleteList();//������� ������� ��������� ��������
    if (!isRoot) delete this;//����� ����
}

template <class T>
void MyList<T>::AddElement(T Data, int index)//���������� ����������� ������� ���������� ��������
{
    if (index < 0) exception("bad index");
    if (index == 0) this->Next = new MyList(Data, this->Next);//���� ������ ����� 0 �� ���� ��������� �� ��� �������
    else if (this == nullptr)throw exception("segmenttion fold)))))");//���� ������� �� ������� ������ - ��������
    else this->Next->AddElement(Data, index - 1);//���� ��� ���� ������ �������� ������
}

template <class T>
void MyList<T>::PrintAll()//���������� ����������� ������� ������ ���� ���������
{
    if (this == nullptr)return;//���� ��� ����� �� �������
    else if (!isRoot)//���� �� 1 �������, �� ��������
    {
        cout << this->Data << " ";
    }
    if ( this->Next != nullptr )
    this->Next->PrintAll();//� �������� ��� ������� � ���������� ��������
}

template <class T>
T & MyList<T>::operator[](int index)//����������� ���������� ��������� []
{
    if (index < 0) exception("bad index");
    //���� ������� �� ���������� �� ������� ��� ���� ��� ������ ������� � ��������� �� ����������
    if (this == nullptr || (isRoot && this->Next == nullptr)) throw exception("out from list in []");
    if (isRoot) return this->Next->operator[](index);//���� ������ ������� �� ������ ���� ������
    if (index == 0) return this->Data;//���� ����� ������ ���� ������� �� ������
    else return this->Next->operator[](index - 1);//���� ����� 1 �� ��������� ��������� ���� ������
}

template <class T>
int MyList<T>::GetSize()//������� ��������� �������
{
    if (isRoot && this->Next == nullptr) return 0;//���� ���� ������ ������� ������� ������ 0
    if (isRoot) return this->Next->GetSize();// ����� ������� ����� �����
    else if (this->Next == nullptr) return 1;//���� ��� ����� ���������� 1;
    else return this->Next->GetSize() + 1;//���� �� ����� ������� ������� ������ � ��������� ����
}

template <class T>
void MyList<T>::DeleteElement(int index)
{
    if (isRoot)//���� ��� 1 ������� �������������� ��� ������� ��������
    {
        if (index < 0) throw exception("bad index");
        if (index == 0 && this->Next != nullptr)//���� ����� ������� 1 �������
        {
            MyList* temp = this->Next->Next;
            delete this->Next;
            this->Next = temp;
            return;
        }

        if (index == 0 && this->Next == nullptr) throw exception("bad index");//���� �� ���������� 1 ��������
    }


    if (index != 0) this->Next->DeleteElement(index - 1);//���� ��� �� ����� ���� ������
    else
    {
        MyList* temp = this->Next->Next;//���� ��� ������ ������� ������� ���
        delete this->Next;
        this->Next = temp;
        return;
    }
}
#endif // !_H_MY_LIST



