#pragma once
#include "Graphh.h"
using namespace std;
class Algorithm
{
	   Graphh primMST(Graphh graph);             // Implements Prim's algorithm to find the minimum spanning tree (can be a method in Graph class as well)
	   Graphh bfs(Graphh graph, City start);    // Performs Breadth - First Search traversal
	   Graphh dfs(Graphh graph, City start);   // Performs Depth - First Search traversal
};

