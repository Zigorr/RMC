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
	void findCity(string start, string end);
	void addEdge(City start, City end, int weight);
	unordered_map<string, City> getMap();
	void setMap(unordered_map<string, City> map);

	//saveToFile();                  // Saves the graph data(cities and edges) to a file
	//loadFromFile();               // Loads the graph data(cities and edges) from a file(You can implement this during program initialization)
};