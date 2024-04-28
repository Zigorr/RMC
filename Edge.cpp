#include "Edge.h"
#include<iostream>
#include "Graphh.h"
#include "City.h"
#include <list>
#include <unordered_map>
#include<vector>
using namespace std;

Edge::Edge(string startCity, string endCity, int weight)
{
	this->startCity = startCity;
	this->endCity = endCity;
	this->weight = weight;
}
Edge::Edge(string endCity, int weight)
{
	this->endCity = endCity;
	this->weight = weight;
}
Edge::~Edge()
{
	//cout << "int";
}
//City Edge::getcity1()
//{
//	return startCity;
//}
//City Edge::getcity2()
//{
//	return endCity;
//}
//int Edge::getweight()
//{
//	return weight;
//}
//void Edge::addEdge(list<City> cities, string startCity, string endCity, int weight)
//{
//	//startCity->cities.push_back(endCity); //Add edge from start to end
//	//endCity->cities.push_back(startCity); // Add edge from end to 
//}


//void Edge::add(string startCity, string endCity, int weight,list<City>cities)
//{
//	string ans; 
//	City c;
//	cout << "Enter yes to add edge" << endl;
//	cin >> ans;
//	
//	while (ans == "yes")
//	{//(dis.find(startCity) != dis.end() && dis.find(endCity) != dis.end()
//		list<City>::iterator it;
//	
//		for(auto it = cities.begin(); it!=cities.end();it++ )
//
//		if (cities.front() == startCity && cities.front() == endCity)// find return iterator f bshoof lw howa not equal end f batli kdh la2ha
//		{
//			if (dis[endCity].front().first == startCity)
//			{
//				cout << "Road is already exist" << endl;
//			}
//			else
//			{
//				end.push_back(make_pair(startCity, weight));
//				dis[startCity].push_back(make_pair(endCity, weight));
//
//				//start dis[Cairo] = { {Alexandria, 220},{aswan ,1000} }
//				//end dis[Alexandria] = { {cairo, 220} }
//				cout << "Edge added successfully from " << startCity << " to " << endCity << " with weight " << weight << endl;
//			}
//		}
//		else
//		{
//			cout << "Error: Cities " << startCity << " and " << endCity << " not found." << endl;
//			cout << "Enter the two cities" << endl;
//			for (int i = 0; i < 2; i++)
//			{
//				c.addcity();
//			}
//		}
//			
//		cout << "if you want to add another edge (yes) " << endl;
//		cin >> ans;
//	}
//}

Edge::Edge()
{
	weight = 0;
}

void Edge::addEdge(string startCity, string endCity, int weight, vector<City>& cities)
{
	if (egd.empty()) 
	{
		egd[startCity].push_back(Edge(startCity, weight));
		egd[endCity].push_back(Edge(endCity, weight));
		cities.push_back(startCity);
		cities.push_back(endCity);
	}
	else
	{     //egd[startCity].find(startCity) == egd.end() && egd.find(endCity) == egd.end()
		if (egd.find(startCity) == egd.end() && egd.find(endCity) == egd.end())
		{
			
			egd[startCity].push_back(Edge(startCity, weight));
			egd[endCity].push_back(Edge(endCity, weight));
		}
		else
		{
			cout << "Road is already exist" << endl;
		}
	}
	//since graph is undirected, add an edge from both vertex u to vertex v and vertex v to vertex u
}
