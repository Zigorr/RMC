#pragma once
#include "City.h"
#include<string>
#include<iostream>
#include <list>
#include <unordered_map>
using namespace std;
class Edge
{
public:
	
	string startCity;
	string endCity;
	int weight=0;
	
	unordered_map<string,vector<pair<string, int>>> dis;

	unordered_map<string,vector<Edge>> egd;

	vector<pair<string,int>> end;
	vector <pair<string, int>>getlist();

	/*string getcity1();
	string getcity2();
	int getweight();*/

    //void addEdge(list<City> cities , string startCity,string endCity, int weight);

	void addEdge(string startCity, string endCity,int weight, vector<City>& cities);
	Edge();
	Edge(string, int);
	Edge(string,string,int);
	~Edge(); 
};