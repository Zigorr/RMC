#pragma once
#include<string>
#include<vector>
using namespace std;
class Edge {
private:
	string startCity;
	string endCity;
	int weight;
public:
	Edge();
	Edge(string startCity, string endCity, int weight);
	string getStartCity();
	string getEndCity();
	int getWeight();
};