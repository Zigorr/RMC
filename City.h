#pragma once
#include "Edge.h"
#include<vector>
#include <string>
using namespace std;
class City {
private:
	string cityName;
	vector<Edge>edges;
public:
	City();
	City(string cityname);
	string getCityName() const;

	void setCityName(string cityName);
	vector<Edge>getEdges() const;

	void setEdges(vector<Edge> v);
};