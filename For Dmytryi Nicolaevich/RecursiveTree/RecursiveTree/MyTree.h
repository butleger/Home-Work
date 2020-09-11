#pragma once
#ifndef _H_MY_TREE

#include <iostream>
#define _H_MY_TREE

template <class T>
class MyTree
{
public :

	void PrintAll();
	void AddElement(T Data);
	bool Find(T Data);
	bool IsFull();
	void DeleteTree();
	int GetSize();


	MyTree();
private :

	MyTree<T>* Left;
	MyTree<T>* Right;
	bool IsRoot;
	T Data;

	MyTree(T Data);
};

template <class T>
void MyTree<T>::AddElement(T Data)
{
	if (this->IsRoot)
	{
		if (this->Left == nullptr) this->Left = new MyTree<T>(Data);
		else this->Left->AddElement(Data);

		return;
	}
	if (this->Data < Data)
	{
		if (this->Right != nullptr) this->Right->AddElement(Data);
		else this->Right = new MyTree<T>(Data);
	} 
	else
	{
		if (this->Left != nullptr) this->Left->AddElement(Data);
		else this->Left = new MyTree<T>(Data);
	}
}

template <class T>
bool MyTree<T>::Find(T Data)
{
	if (this->IsRoot)
	{
		if (this->Left != nullptr)return this->Left->Find(Data);
		else return false;

	}
	if (this->Data == Data) return true;
	if (this->Data < Data && this->Right != nullptr) return this->Right->Find(Data);
	if (this->Data > Data&& this->Left != nullptr) return this->Left->Find(Data);
	return false;
}

template <class T>
bool MyTree<T>::IsFull()
{
	if (this->IsRoot)
	{
		if (this->Left == nullptr)return true;
		else return this->Left->IsFull();
	}
	if (this == nullptr || (this->Left == nullptr && this->Right == nullptr ) )return true;
	if ((this->Left != nullptr && this->Right == nullptr) || (this->Left == nullptr && this->Right != nullptr)) return false;
	else return this->Left->IsFull() && this->Right->IsFull();
}

template <class T>
void MyTree<T>::DeleteTree()
{
	if (this->IsRoot)
	{
		if (this->Left == nullptr) return;
		else this->Left->DeleteTree();
		return;
	}
	if (this->Left != nullptr)this->Left->DeleteTree();
	if (this->Right != nullptr)this->Right->DeleteTree();
	delete this;
}

template <class T>
int MyTree<T>::GetSize()
{
	if (this->IsRoot)
	{
		if (this->Left == nullptr)return 0;
		else return this->Left->GetSize();
	}
	int Size = 0;
	if (this->Left != nullptr) Size += this->Left->GetSize();
	if (this->Right != nullptr) Size += this->Right->GetSize();
	return Size + 1;
}

template <class T>
MyTree<T>::MyTree(T Data)
{
	this->Data = Data;
	this->IsRoot = false;
	this->Left = nullptr;
	this->Right = nullptr;
}

template <class T>
MyTree<T>::MyTree()
{
	this->IsRoot = true;
	this->Left = nullptr;
	this->Right = nullptr;
}

template <class T>
void MyTree<T>::PrintAll()
{
	if (this->IsRoot)
	{
		if (this->Left == nullptr)return;
		else this->Left->PrintAll();

		return;
	}

	if (this->Left != nullptr) this->Left->PrintAll();
	std::cout << this->Data << " ";
	if (this->Right != nullptr) this->Right->PrintAll();
}
#endif // !_H_MY_TREE


