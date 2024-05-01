#pragma once
#include<string>
#include<vector>
using namespace std;
class Edge {
private:
	string startcity;
	string endcity;
	int weight;
public:
	Edge();
	Edge(string startcity, string endcity, int weight);
	string getstartcity();
	string getendcity();
	int getweight();
};