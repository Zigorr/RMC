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
#include <chrono>
#include <thread>
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
void Graph::findCity(string start,string end)
{
    string answer;
    if (cities.find(start) == cities.end())
    {
        cout << start << " does not exist." << endl;
        cout << "Do you want to add " << start << "?" << endl;
        cin >> answer;
        if (answer == "Yes" || answer == "yes")
        {
            City c(start);
            addCity(c);
        }
        else
        {
            cout << "Returning to menu." << endl;
            return;
        }
    }

    if (cities.find(end) == cities.end())
    {
        cout << end << " does not exist." << endl;
        cout << "Do you want to add " << end << "?" << endl;
        cin >> answer;
        if (answer == "Yes" || answer == "yes")
        {
            City c(end);
            addCity(c);
        }
        else
        {
            cout << "Returning to menu." << endl;
            return;
        }
    }

    cout << start << " and " << end << " exist." << endl;
}
void Graph::addEdge(City start, City end, int weight)
{
    // Check if start and end cities exist in the graph, add them if they don't
    findCity(start.getCityName(), end.getCityName());

    // Retrieve the edges of the start city
    vector<Edge> startCityEdges = cities[start.getCityName()].getEdges();

    // Create the new edge
    Edge newEdge(start.getCityName(), end.getCityName(), weight);

    // Add the new edge to the start city's edges
    startCityEdges.push_back(newEdge);
    cities[start.getCityName()].setEdges(startCityEdges);

    // Update the adjacency list for the start city
    adjacencyList[start.getCityName()].push_back(make_pair(end.getCityName(), weight));
    adjacencyList[end.getCityName()].push_back(make_pair(start.getCityName(), weight));

    // Output the edges for verification
    cout << "Edges after adding new edge:" << endl;
    for (const auto& edge : startCityEdges)
    {
        cout << "Start: " << edge.getStartCity() << ", End: " << edge.getEndCity() << ", Weight: " << edge.getWeight() << endl;
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

        // Check if city exists in the adjacency list
        if (adjacencyList.find(city) == adjacencyList.end()) {
            cout << "Error: Adjacency list for city " << city << " not found." << endl;
            break;
        }

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
        cout << "City " << startCity << " does not exist in the graph." << endl;
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

        for (const auto& neighbor : cities.at(city).getEdges()) {
            if (visited.find(neighbor.getEndCity()) == visited.end()) {
                q.push(neighbor.getEndCity());
                visited.insert(neighbor.getEndCity());
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

void Graph::displayGraphData()
{
    if (cities.empty())
    {
        cout << "Graph is empty." << endl;
        return;
    }

    // Display cities and their edges
    cout << "Cities in the graph:" << endl;
    for (const auto& city : cities)
    {
        cout << city.first << ":" << endl;
        for (const auto& edge : city.second.getEdges())
        {
            cout << "  - " << edge.getEndCity() << " (Weight: " << edge.getWeight() << ")" << endl;
        }

        // Display reverse edges
        for (const auto& reverseEdge : cities[city.first].getEdges())
        {
            cout << "  - " << reverseEdge.getEndCity() << " (Weight: " << reverseEdge.getWeight() << ")" << endl;
        }
        cout << endl;
    }

    // Add a delay of 2 seconds before returning to the menu
    std::this_thread::sleep_for(std::chrono::seconds(2));
}