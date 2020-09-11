#pragma once
#ifndef _GRAPH_H_
#include <string>

class Graph
{
public :
    Graph();
    Graph(int** graph, int size);
    ~Graph();
    void CreateGraphFromConsole();
    bool CreateGraphFromFile(const char * fileName = "no file!");
    void printGraphByDFSPrefix(int startNode = 0, void (*func)(int element) = 0);
    void printGraphByBFS(int startNode = 0, void (*func)(int element) = 0);
    void BFS(int start = 0, void (*func)(int element) = 0);
    void DFS(int start = 0, void (*func)(int element) = 0);
 //   int* Dijkstra(int start = 0, bool JustShow = true);
    int** Floyd(bool JustShow = true);
private :
    void DeleteGraph();
	int quantity;
	int** graph;
};
#endif // !_GRAPH_H_


