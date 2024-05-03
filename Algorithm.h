#pragma once
#include "Graph.h"
using namespace std;
class Algorithm
{
	   Graph primMST(Graph graph);             // Implements Prim's algorithm to find the minimum spanning tree (can be a method in Graph class as well)
	   Graph bfs(Graph graph, City start);    // Performs Breadth - First Search traversal
	   Graph dfs(Graph graph, City start);   // Performs Depth - First Search traversal
};

