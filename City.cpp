#include "Edge.h"
#include "City.h"
using namespace std;

City::City()
{
	cityname = "";
}

City::City(string cityname)
{
	this->cityname = cityname;
}

string City::getcityname()
{
	return cityname;
}

void City::setcityname(string cityname)
{
	this->cityname = cityname;
}

vector<Edge> City::getedges()
{
	return edges;
}

void City::setedges(vector<Edge> v)
{
	 edges = v;
}


