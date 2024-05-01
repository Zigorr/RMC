#include "Edge.h"

using namespace std;

Edge::Edge()
{
	startcity = "";
	endcity = "";
	weight = 0;
}

Edge::Edge(string startcity, string endcity, int weight)
{
	this->startcity = startcity;
	this->endcity = endcity;
	this->weight = weight;
}

string Edge::getstartcity()
{
	return startcity;
}

string Edge::getendcity()
{
	return endcity;
}

int Edge::getweight()
{
	return weight;
}
