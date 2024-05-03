#pragma once
#include<list>
#include "City.h"
#include "Edge.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
class Graph {


	//Methods :
public:
	unordered_map<string, City>cities;
	void addCity(City city);
	void deleteCity(City city);
	void  deleteEdge(Edge e);
	void findcity(string start, string end);
	void addEdge(City start, City end, int weight);
	unordered_map<string, City> getmap();
	void setmap(unordered_map<string, City> map);
	//Edge findMST();                   // Implements Prim's algorithm to find the minimum spanning tree and returns the total distance
	//void traverseBFS(City start);    // Performs Breadth - First Search starting from a city // deleteEdge(City start, City end);
	//void traverseDFS(City start);   // Performs Depth - First Search starting from a city
	//saveToFile();                  // Saves the graph data(cities and edges) to a file
	//loadFromFile();               // Loads the graph data(cities and edges) from a file(You can implement this during program initialization)
};