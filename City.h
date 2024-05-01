#pragma once
#include "Edge.h"
#include<vector>
#include <string>
using namespace std;
class City {
private:
	string cityname;
	vector<Edge>edges;
public:
	City();
	City(string cityname);
	string getcityname();
	void setcityname(string cityname);
	vector<Edge>getedges();
	void setedges(vector<Edge> v);
};