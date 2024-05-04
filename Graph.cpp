#include "Graph.h"
#include "Menu.h"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Menu.h"
#include "City.h"
using namespace std;
vector<Edge> v;// temp vector
City c;
unordered_map<string, City> Graph::getMap()
{
    return unordered_map<string, City>();
}

void Graph::setMap(unordered_map<string, City> map)
{
    cities = map;
}
void Graph::addCity(City city)
{
    if (cities.find(city.getCityName()) != cities.end())
    {
        cout << "City already exits" << endl;
    }
    else
    {
        cities[city.getCityName()] = {}; //Initialize with an empty vector of edges
        cout << city.getCityName() << " added successfully" << endl;
    }

}
void Graph::findCity(string start, string end)
{
    vector<Edge>temp;
    v = c.getEdges();
    string answer;
    if (cities.find(start) != cities.end())
    {
        cout << start << " exists" << endl;
    }
    else
    {
        cout << start << " does not exist" << endl;
        cout << "Do you want to add " << start << "?" << endl;
        cin >> answer;
        if (answer == "Yes" || answer == "yes")
        {
            City c(start);
            addCity(c);
        }
        else
        {
            Menu m;
            m.display();
        }
    }
    if (cities.find(end) != cities.end())
    {
        cout << end << " exists" << endl;
    }
    else
    {
        cout << end << " does not exist" << endl;
        cout << "Do you want to add " << end << "?" << endl;
        cin >> answer;
        if (answer == "Yes" ||  answer == "yes")
        {
            City c2(end);
            addCity(c2);
        }
        else
        {
            Menu m;
            m.display();
        }
    }
}
void Graph::addEdge(City start, City end, int weight)
{
        City c1(start); // ll constructor
        City c2(end);
       
        findCity(c1.getCityName(), c2.getCityName());

        Edge e(start.getCityName(), end.getCityName(), weight);
        Edge e1(end.getCityName(), start.getCityName(), weight);

        v = c.getEdges(); // v = edges

        v.push_back(e);
        v.push_back(e1);

        c.setEdges(v); // brg3 fy fy edges 

        cities[c1.getCityName()] = { {c2} };
        cities[c2.getCityName()] = { {c1} };

        vector<Edge>::iterator it;
        for (it = v.begin(); it != v.end(); it++)
        {
            cout << "Start: " << it->getStartCity() << ", End: " << it->getEndCity() << ", Weight: " << it->getWeight() << endl;
        }
}
void Graph::deleteCity(City city)
{
    string cityName = city.getCityName();
    auto it = cities.find(cityName);

    if (it != cities.end())
    {
        cities.erase(it);

        vector<Edge> edges = c.getEdges();
        vector<Edge> tempEdges;

        for (auto it = edges.begin(); it != edges.end(); ++it)
        {
            if (it->getStartCity() != cityName && it->getEndCity() != cityName)
            {
                tempEdges.push_back(*it);
            }
        }

        c.setEdges(tempEdges);
        cout << "City " << cityName << " and its associated edges deleted successfully." << endl;
    }
    else
    {
        cout << cityName << " does not exist." << endl;
    }
}

void Graph::deleteEdge(Edge e)
{
    vector<Edge> temp;
    v = c.getEdges();
    bool edgeDeleted = false;

    for (auto it = v.begin(); it != v.end(); ++it) {
        if (it->getStartCity() != e.getStartCity() || it->getEndCity() != e.getEndCity() || it->getWeight() != e.getWeight())
        {
            temp.push_back(*it);
        }
        else
        {
            edgeDeleted = true;
        }
    }

    if (edgeDeleted)
    {
        cout << "Edge deleted successfully." << endl;
        v = temp;
        c.setEdges(v);
    }
    else
    {
        cout << "Edge with the specified details not found." << endl;
    }

    cout << "Remaining edges:" << endl;
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << "Start: " << it->getStartCity() << " -> " << "End: " << it->getEndCity() << " Weight: " << it->getWeight() << endl;
    }
}