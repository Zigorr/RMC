#include "Edge.h"

using namespace std;

Edge::Edge()
{
	startCity = "";
	endCity = "";
	weight = 0;
}

Edge::Edge(string startCity, string endCity, int weight)
{
	this->startCity = startCity;
	this->endCity = endCity;
	this->weight = weight;
}

string Edge::getStartCity() const
{
	return startCity;
}

string Edge::getEndCity() const
{
	return endCity;
}

int Edge::getWeight() 
	const
{
	return weight;
}
