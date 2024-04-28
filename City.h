#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include<list>
#include <unordered_map>
#include "Edge.h"


using namespace std;

class City
{
public:
	// void Input() = 0;
	//virtual string getName() const = 0;
	//vector<pair<string, double>> getConnectedCities() const = 0;
	
     // list<pair<string,Edge>> connectedEdges; // linked list byshawer 3la edges bta3t one city
	vector<City> cities;  
	// list mn cities add city 
	unordered_map<string,vector<pair<string, int>>> myMap;
	// for display
	// cairo alex aswan 
	City(string cityName);
	City(string cityName, string city1Name);
	City();
	bool findcity();
	string getName() ; 
	void addcity();
protected:
	string name;
	//vector<pair<string, double>> connectedCities;
};