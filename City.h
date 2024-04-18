#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class City
{
	public:
	virtual void Input() = 0;
	virtual string getName() const = 0;
	virtual vector<pair<string, double>> getConnectedCities() const = 0;
protected:
	string name;
	vector<pair<string, double>> connectedCities;
};

