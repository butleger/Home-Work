#include "Graph.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <queue>
using namespace std;

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
