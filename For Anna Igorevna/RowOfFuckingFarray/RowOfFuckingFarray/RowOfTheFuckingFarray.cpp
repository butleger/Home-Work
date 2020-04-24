#include "RowOfTheFuckingFarray.h"
#include <iostream>
using namespace std;

int FarrayRow::getLevel()
{
	return Level;
}

FarrayRow::FarrayRow(Fraction first, Fraction second) :
	MyList(),
	Level(1)
{
	PushFront(second);
	PushFront(first);
}

void FarrayRow::Add_before()
{
	return;
}

void FarrayRow::Show()
{
	cout << *dynamic_cast<MyList<Fraction> *>(this);
}

void FarrayRow::Clear()
{
	Node* temp = head;
	Node* help = temp;
	while (temp != 0)
	{
		help = temp;
		temp = temp->next;
		delete help;
	}
	head = 0;
}

void FarrayRow::Increase()
{
	Level++;
	for (Node* temp = head; temp->next != 0; temp = temp->next)
	{
		if (temp->info.second + temp->next->info.second <= Level)
		{
			temp->next = new Node(
				Fraction(temp->info.first + temp->next->info.first,
						temp->info.second + temp->next->info.second),
				temp->next);
			temp = temp->next->next;

		}
	}
}
