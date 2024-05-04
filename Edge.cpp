#include "Edge.h"

using namespace std;

Edge::Edge()
{
	startCity = "";
	endCity = "";
	weight = 0;
}

Edge::Edge(string startcity, string endcity, int weight)
{
	this->startCity = startcity;
	this->endCity = endcity;
	this->weight = weight;
}

string Edge::getStartCity()
{
	return startCity;
}

string Edge::getEndCity()
{
	return endCity;
}

int Edge::getWeight()
{
	return weight;
}
