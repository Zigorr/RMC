#include "Edge.h"
#include "City.h"
using namespace std;

City::City()
{
	cityName = "";
}

City::City(string cityname)
{
	this->cityName = cityname;
}

string City::getCityName() const
{
	return cityName;
}

void City::setCityName(string cityname)
{
	this->cityName = cityname;
}

vector<Edge> City::getEdges() const
{
	return edges;
}

void City::setEdges(vector<Edge> v)
{
	 edges = v;
}


