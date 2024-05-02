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
void Graphh::deleteCity(City city) {
    bool cityDeleted = false;
    vector<Edge>temp; // Use a new vector for clarity
    unordered_map<string, City> tmap;
    tmap = getmap();
    v = c.getedges();

    auto it = tmap.find(city.getcityname());

    // Check if the city exists in the map
    if (it != tmap.end()) {
        // Erase the entry using the iterator
        tmap.erase(it);

        // Iterate through edges, removing matching ones
        for (auto it = v.begin(); it != v.end(); ) {
            if (it->getstartcity() != city.getcityname() && it->getendcity() != city.getcityname()) {
                temp.push_back(*it);
                ++it; // Move iterator only if the edge is kept
            }
            else {
                cityDeleted = true;
                it = v.erase(it); // Erase the matching edge and update iterator
            }
        }

        if (cityDeleted) {
            cout << "City deleted successfully." << endl;
            v = temp; // Now assign the new vector with removed edges to v
        }
        else {
            cout << "City with the specified details not found." << endl;
        }
        cout << "Remaining Edges:" << endl;
        for (auto it = v.begin(); it != v.end(); it++) {
            cout << " Start : " << it->getstartcity() << " -> "
                << " ( End : " << it->getendcity() << " , Weight  " << it->getweight() << " ) -> " << endl;
        }
        c.setedges(temp);
    }
}
void Graphh::deleteEdge(Edge e)
{
    vector<Edge>temp;
    v = c.getedges();
   
    bool edgeDeleted = false; // Flag to track if any edge was deleted
    //125
    for (auto it = v.begin(); it != v.end(); ++it) {
        if (((it->getstartcity() != e.getstartcity() && it->getendcity() != e.getendcity() && it->getweight() != e.getweight()) ||(it->getstartcity() != e.getendcity() && it->getendcity() != e.getstartcity() && it->getweight() != e.getweight()))) {
            temp.push_back(*it);
        }
        else {
            edgeDeleted = true;
        }
    }
    if (edgeDeleted) {
        cout << "Edge deleted successfully." << endl;
        v = temp;
    }
    else
    {
        cout << "Edge with the specified details not found." << endl;
    }
    cout << "Remaining edges:" << endl;
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << " Start : " << it->getstartcity() << " -> " << " ( End : " << it->getendcity() << " , Weight  " << it->getweight() << " ) -> " << endl;
    }
    c.setedges(temp);   
}