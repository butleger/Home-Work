#include "Graph.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
#define min(x,y) (x) > (y) ? y : x
using namespace std;

int constexpr Max = INT_MAX;
//some comments
//комментарии
Graph::Graph() :
	graph(0),
	quantity(0)
{}

Graph::Graph(int** graph, int size) :
	graph(graph),
	quantity(size)
{
}

Graph::~Graph()
{
	DeleteGraph();
}

void Graph::CreateGraphFromConsole()
{
	if (graph != 0) DeleteGraph();

	cout << "Input quantity of graph members : ";
	cin >> quantity;
	cout << "Input adjacency matrix : \n";

	graph = new int*[quantity];
	for (int i = 0; i < quantity; i++)
		graph[i] = new int[quantity];
	
	for (int i = 0; i < quantity; i++)
		for (int j = 0; j < quantity; j++)
			cin >> graph[i][j];
}

bool Graph::CreateGraphFromFile(const char * _fileName)
{
	string fileName(_fileName);
	if (fileName == "no file!" )
	{
		cout << "Input filename : ";
		cin >> fileName;
	}

	fstream fin(fileName);

	if (!fin.is_open())
	{
		cout << "File was not opened!\n";
		return false;
	}

	fin >> quantity;
	for (int i = 0; i < quantity; i++)
		for (int j = 0; j < quantity; j++)
			fin >> graph[i][j];

	return true;
}

void Graph::DeleteGraph()
{
	if (graph == 0) return;

	for (int i = 0; i < quantity; i++)
		delete[] graph[i];
	delete[] graph;
}

void Graph::BFS(int start, void(*func)(int element))
{
	if (graph == 0) return;

	void (*DoStaff)(int);

	if (func == 0)
		DoStaff = [](int element)
	{
		cout << element << " ";
	};
	else DoStaff = func;


	queue<int> q;
	bool* isUsed = new bool[quantity];
	for (int i = 0; i < quantity; i++)
		isUsed[i] = 0;

	isUsed[start] = true;
	q.push(start);

	while (!q.empty())
	{
		int temp = q.front(); q.pop();
		for (int i = 0; i < quantity; i++)
			if (graph[temp][i] != 0 && !isUsed[i])
			{
				q.push(i);
				isUsed[i] = true;
			}
		DoStaff(temp);
	}

	delete[] isUsed;

}

void Graph::DFS(int start, void(*func)(int element))
{
	if (graph == 0)return;

	void (*DoStaff)(int element);
	if (func == 0) DoStaff = [](int element) {cout << element << " "; };
	else DoStaff = func;

	bool* isUsed = new bool[quantity];
	for_each(isUsed, isUsed + quantity, [](bool& el) {el = 0; });
	stack<int> s;
	s.push(start);
	isUsed[start] = true;

	while (!s.empty())
	{
		int temp = s.top(); s.pop();
		for ( int i = 0 ; i < quantity ;i++ )
			if (graph[temp][i] != 0 && !isUsed[i])
			{
				s.push(i);
				isUsed[i] = true;
			}
		DoStaff(temp);
	}

	delete[] isUsed;

}

int** Graph::Floyd(bool JustShow)
{
	if (graph == 0) return nullptr;

	int** tempMatrix = new int*[quantity];
	for (int i = 0; i < quantity; i++)
		tempMatrix[i] = new int[quantity];

	for (int i = 0; i < quantity; i++)
		for (int j = 0; j < quantity; j++)
			tempMatrix[i][j] = graph[i][j];

	for (int k = 0 ; k < quantity ; k++ )
		for (int i = 0 ; i < quantity ; i++ )
			for (int j = 0; j < quantity ; j++)
			{
				if (tempMatrix[i][k] == 0 || tempMatrix[k][j] == 0 ) continue;

				tempMatrix[i][j] = min(tempMatrix[i][j], tempMatrix[i][k] + tempMatrix[k][j]);

				if (tempMatrix[i][j] == 0 && i != j)tempMatrix[i][j] = tempMatrix[i][k] + tempMatrix[k][j];
			}
	if (JustShow)
	{
		for (int i = 0; i < quantity; i++) {
			for (int j = 0; j < quantity; j++)
				cout << tempMatrix[i][j] << " ";
			cout << endl;
		}

		for (int i = 0; i < quantity; i++)
			delete[] tempMatrix[i];
		delete[] tempMatrix;
		tempMatrix = nullptr;
	}
	
	return tempMatrix;
	
}

//int* Graph::Dijkstra(int start, bool JustShow)
//{
//	if (graph == 0) return nullptr;
//	int* Distance = new int[quantity];
//	bool* isMarked = new bool[quantity];
//
//	for_each(isMarked, isMarked + quantity,
//		[](bool& elem) {elem = false; });
//	for_each(Distance, Distance + quantity,
//		[](int& elem) {elem = Max; });
//
//	queue<int> q;
//	q.push(start);
//	Distance[start] = 0;
//
//	while (!q.empty())
//	{
//		int temp = q.front(); q.pop();
//		for ( int i = 0 ; i < quantity ; i++ )
//			if (graph[temp][i] != -1 && !isMarked[i])
//			{
//				Distance[i]
//			}
//	}
//
//
//	delete[] isMarked;
//	if (JustShow)
//	{
//		for_each(Distance, Distance + quantity,
//			[](int elem) {cout << elem << " "; });
//
//		delete[] Distance;
//		return nullptr;
//	}
//	else
//		return Distance;
//}

void Graph::printGraphByDFSPrefix(int startNode, void (*func)(int element))
{
	if (startNode < 0 || startNode >= quantity)
	{
		cout << "Bad index in DFS!\n";
		return;
	}
	if (graph == 0)
	{
		cout << "You trying use DFS without a graph!\n";
		return;
	}
	void (*DoStaff)(int element) = [](int element)
	{
		cout << element << " ";
	};
	bool * isUsed = new bool[quantity];
	for (int i = 0; i < quantity; i++)
		isUsed[i] = 0;
	isUsed[startNode] = true;
	stack<int> s;
	s.push(startNode);
	
	while (!s.empty())
	{
	int temp = s.top(); s.pop();
		for (int i = 0; i < quantity; i++)
		{
			if (!isUsed[i] && graph[temp][i] != 0)
			{
				isUsed[i] = true;
				s.push(i);
			}
		}
	
	DoStaff(temp);
	}

	delete[] isUsed;
}

void Graph::printGraphByBFS(int startNode, void (*func)(int element))
{

	if (startNode < 0 || startNode >= quantity)
	{
		cout << "Bad index in DFS!\n";
		return;
	}
	if (graph == 0)
	{
		cout << "You trying use DFS without a graph!\n";
		return;
	}
	void (*DoStaff)(int element) = [](int element)
	{
		cout << element << " ";
	};
	bool* isUsed = new bool[quantity];
	for (int i = 0; i < quantity; i++)
		isUsed[i] = 0;
	isUsed[startNode] = true;
	queue<int> q;
	q.push(startNode);

	while (!q.empty())
	{
		int temp = q.front(); q.pop();
		for (int i = 0; i < quantity; i++)
		{
			if (!isUsed[i] && graph[temp][i] != 0)
			{
				isUsed[i] = true;
				q.push(i);
			}
		}

		DoStaff(temp);
	}

	delete[] isUsed;

}
