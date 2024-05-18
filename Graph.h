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
class Graph 
{    
public:
    void addCity(City city);
    void  deleteEdge(Edge e);
    void findCity(string start, string end);
    void addEdge(City start, City end, int weight);
    void deleteCity(string cityName);
    unordered_map<string, City> getMap();
    void setMap(unordered_map<string, City> map);
    void findMST();               // Find MST using Prim's algorithm
    void BFS(string startCity);  // Perform Breadth First Search traversal
    void DFS(string startCity); // Perform Depth First Search traversal
    void displayGraphData();
    void dijkstra(string startCity);
    unordered_map<int, Graph> getGraph();
    void setGraph(unordered_map<int, Graph> graph);
    void writeToFile(const string& filename);
    unordered_map<int, Graph> readFromFile(const string& filename );
      
private:
    unordered_map<string,City> cities;
    unordered_map<int,Graph> graphs;
};
