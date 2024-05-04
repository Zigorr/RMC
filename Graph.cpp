#include "Graph.h"
#include "Menu.h"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Menu.h"
#include "City.h"
#include <stack>
#include <unordered_set>
#include <queue>
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
void Graph::findMST() const {
    if (cities.empty()) {
        cout << "Graph is empty. Cannot find Minimum Spanning Tree." << endl;
        return;
    }
    
    
    unordered_set<string> visited;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

    // Start with first city
    pq.push(make_pair(0, cities.begin()->first));

    int totalDistance = 0;
    cout << "Minimum Spanning Tree:" << endl;
    while (!pq.empty()) {
        string city = pq.top().second;
        int distance = pq.top().first;
        pq.pop();

        // If city already visited, skip
        if (visited.find(city) != visited.end()) {
            continue;
        }

        visited.insert(city);
        totalDistance += distance;
        cout << "From: " << city;
        if (city != cities.begin()->first) {
            cout << ", Distance: " << distance;
        }
        cout << endl;

        // Add neighbors to priority queue
        for (const auto& neighbor : adjacencyList.at(city)) {
            if (visited.find(neighbor.first) == visited.end()) {
                pq.push(make_pair(neighbor.second, neighbor.first));
            }
        }
    }
    cout << "Total Distance of Minimum Spanning Tree: " << totalDistance << endl;
}

// Function to perform BFS traversal
void Graph::BFS(const string& startCity) const {
    if (cities.find(startCity) == cities.end()) {
        cout << "City " << startCity << " Does not exist in the graph." << endl;
        return;
    }
    unordered_set<string> visited;
    queue<string> q;

    q.push(startCity);
    visited.insert(startCity);

    cout << "Breadth First Search traversal starting from " << startCity << ":" << endl;
    while (!q.empty()) {
        string city = q.front();
        q.pop();
        cout << city << " ";

        for (const auto& neighbor : adjacencyList.at(city)) {
            if (visited.find(neighbor.first) == visited.end()) {
                q.push(neighbor.first);
                visited.insert(neighbor.first);
            }
        }
    }
    cout << endl;
}

// Function to perform DFS traversal
void Graph::DFS(const string& startCity) const {
    if (cities.find(startCity) == cities.end()) {
        cout << "City " << startCity << " does not exist in the graph." << endl;
        return;
    }
    unordered_set<string> visited;
    stack<string> s;

    s.push(startCity);

    cout << "Depth First Search traversal starting from " << startCity << ":" << endl;
    while (!s.empty()) {
        string city = s.top();
        s.pop();

        if (visited.find(city) == visited.end()) {
            cout << city << " ";
            visited.insert(city);

            for (const auto& neighbor : adjacencyList.at(city)) {
                if (visited.find(neighbor.first) == visited.end()) {
                    s.push(neighbor.first);
                }
            }
        }
    }
    cout << endl;
}
void Graph::displayGraphData() {
    if (cities.empty()) {
        cout << "Graph is empty." << endl;
        return;
    }

    cout << "Graph Data:" << endl;
    for (const auto& city : cities) {
        cout << "City: " << city.first << endl;
        cout << "Edges:" << endl;
        for (const auto& edge : city.second.getEdges()) {
            cout << "   Start: " << edge.getStartCity() << ", End: " << edge.getEndCity() << ", Weight: " << edge.getWeight() << endl;
        }
    }
}