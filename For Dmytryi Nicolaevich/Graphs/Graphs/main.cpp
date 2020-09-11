#include <iostream>
#include "Graph.h"
#include <algorithm>
using namespace std;


int main()
{
    Graph graph;
    int start = 0;
    graph.CreateGraphFromConsole();
    graph.Floyd();
    
}
