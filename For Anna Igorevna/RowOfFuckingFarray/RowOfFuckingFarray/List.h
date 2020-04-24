#pragma once
#ifndef _LIST_H_
#define _LIST_H_
#include <iostream>
#include "Fraction.h"
using namespace std;

template <class T>
class MyList
{
protected :
	struct Node
	{
		T info;
		Node* next;
		Node(T info, Node* next = 0) :
			info(info),
			next(next)
		{}
	};

	Node* head;
	ostream& getStream(ostream& out)
	{
		for (Node* temp = head; temp; temp = temp->next)
			out << temp->info << " ";
		return out;
	}
public:
	MyList();
	~MyList();
	
	template <class T1>
	friend ostream& operator<<(ostream& os, MyList<T1>& list);

	void Insert(T info, int index);
	int Count();
	void Remove(int index);
	void PopFront();
	void PushFront(T Data);
	void PopBack();
	void PushBack(T Data);
};

template <class T>
MyList<T>::MyList():
	head(0)
{}

template <class T>
MyList<T>::~MyList()
{
	while (head != NULL)
	{
		Node* help = head->next;
		delete head;
		head = help;
	}
}


template <class T>
ostream& operator<<(ostream& out, MyList<T>& list)
{
	return list.getStream(out);
}

template <class T>
void MyList<T>::Insert(T info, int index)
{
	if (Count() < index || index < 0) throw 1;

	if (index == 0)
	{
		head = new Node(info, head);
		return;
	}
	Node* current = head;
	for (int i = 1; i < index; current = current->next, i++);
	current->next = new Node(info, current->next);
}

template <class T>
void MyList<T>::Remove(int index)
{
	if (Count() <= index || index < 0) throw 1;
	if (index == 0)
	{
		Node* help = head->next;
		delete head;
		head = help;
		return;
	}
	Node* current = head;
	for (int i = 1; i < index; current = current->next, i++);
	Node* help = current->next;
	current->next = help->next;
	delete help;
}

template <class T>
void MyList<T>::PopFront()
{
	if (head == 0) return;
	Node* help = head;
	head = head->next;
	delete help;

}

template<class T>
void MyList<T>::PushFront(T Data)
{
	head = new Node(Data, head);
}

template<class T>
void MyList<T>::PopBack()
{
	if (head == 0)return;

	if (Count() == 1)
	{
		delete head;
		head = 0;
	}

	Node* curr;

	for (curr = head; curr->next->next != 0; curr = curr->next);

	delete curr->next;
	curr->next = 0;
}

template<class T>
void MyList<T>::PushBack(T Data)
{
	Node* curr;
	for (curr = head; curr->next != 0; curr = curr->next);
	curr->next = new Node(Data);
}

template <class T>
int MyList<T>::Count()
{
	int count = 0;
	for (Node* current = head; current != NULL; current = current->next, count++);
	return count;
}



#endif // !_LIST_H_

