#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class City
{
	public:
	// void Input() = 0;
	//virtual string getName() const = 0;
	 //vector<pair<string, double>> getConnectedCities() const = 0;
	

	City(const string cityName);
	
	string getName() const; 
	

protected:
	string name;
	vector<pair<string, double>> connectedCities;
};

