#pragma once
#include<list>
#include "City.h"
#include "Edge.h"
#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <string>
using namespace std;
class Graph {


	//Methods :
public:
	void addCity(City city);
	void deleteCity(City city);
	void  deleteEdge(Edge e);
	void findCity(string start, string end);
	void addEdge(City start, City end, int weight);
	unordered_map<string, City> getMap();
	void setMap(unordered_map<string, City> map);
	void findMST() const; // Find MST using Prim's algorithm
	void BFS(const std::string& startCity) const; // Perform Breadth First Search traversal
	void DFS(const std::string& startCity) const; // Perform Depth First Search traversal

	//saveToFile();                  // Saves the graph data(cities and edges) to a file
	//loadFromFile();               // Loads the graph data(cities and edges) from a file(You can implement this during program initialization)
private:
	std::unordered_map<std::string, City> cities;
	std::unordered_map<std::string, std::list<std::pair<std::string, int>>> adjacencyList; // Adjacency list representation for weighted graph
};