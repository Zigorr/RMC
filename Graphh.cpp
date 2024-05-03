#include "Graphh.h"
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
unordered_map<string, City> Graphh::getmap()
{
    return unordered_map<string, City>();
}

void Graphh::setmap(unordered_map<string, City> map)
{
    cities = map;
}
void Graphh::addCity(City city)
{
    if (cities.find(city.getcityname()) != cities.end())
    {
        cout << "City already exits" << endl;
    }
    else
    {
        cities[city.getcityname()] = {}; //Initialize with an empty vector of edges
        cout << city.getcityname() << " added successfully" << endl;
    }

}
void Graphh::findcity(string start, string end)
{
    vector<Edge>temp;
    v = c.getedges();
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
void Graphh::addEdge(City start, City end, int weight)
{
        City c1(start); // ll constructor
        City c2(end);
       
        findcity(c1.getcityname(), c2.getcityname());

        Edge e(start.getcityname(), end.getcityname(), weight);
        Edge e1(end.getcityname(), start.getcityname(), weight);

        v = c.getedges(); // v = edges

        v.push_back(e);
        v.push_back(e1);

        c.setedges(v); // brg3 fy fy edges 

        cities[c1.getcityname()] = { {c2} };
        cities[c2.getcityname()] = { {c1} };

        vector<Edge>::iterator it;
        for (it = v.begin(); it != v.end(); it++)
        {
            cout << "Start: " << it->getstartcity() << ", End: " << it->getendcity() << ", Weight: " << it->getweight() << endl;
        }
}
void Graphh::deleteCity(City city)
{
    string cityName = city.getcityname();
    auto it = cities.find(cityName);

    if (it != cities.end())
    {
        cities.erase(it);

        vector<Edge> edges = c.getedges();
        vector<Edge> tempEdges;

        for (auto it = edges.begin(); it != edges.end(); ++it)
        {
            if (it->getstartcity() != cityName && it->getendcity() != cityName)
            {
                tempEdges.push_back(*it);
            }
        }

        c.setedges(tempEdges);
        cout << "City " << cityName << " and its associated edges deleted successfully." << endl;
    }
    else
    {
        cout << cityName << " does not exist." << endl;
    }
}

void Graphh::deleteEdge(Edge e)
{
    vector<Edge> temp;
    v = c.getedges();
    bool edgeDeleted = false;

    for (auto it = v.begin(); it != v.end(); ++it) {
        if (it->getstartcity() != e.getstartcity() || it->getendcity() != e.getendcity() || it->getweight() != e.getweight())
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
        c.setedges(v);
    }
    else
    {
        cout << "Edge with the specified details not found." << endl;
    }

    cout << "Remaining edges:" << endl;
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << "Start: " << it->getstartcity() << " -> " << "End: " << it->getendcity() << " Weight: " << it->getweight() << endl;
    }
}