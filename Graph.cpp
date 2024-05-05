#include "Graph.h"
#include "Menu.h"
#include "GraphVisualizer.h"
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
unordered_map<string, City> Graph::getMap() const
{
    return unordered_map<string, City>();
    return cities;
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

    // Check if the edge already exists
    bool edgeExists = false;
    for (const auto& edge : cities[start.getCityName()].getEdges())
    {
        if (edge.getEndCity() == end.getCityName())
        {
            edgeExists = true;
            break;
        }
    }

    if (edgeExists)
    {
        cout << "Edge between " << start.getCityName() << " and " << end.getCityName() << " already exists." << endl;
        return;
    }

    // Retrieve the edges of the start city
    vector<Edge> startCityEdges = cities[start.getCityName()].getEdges();

    // Create the new edge
    Edge newEdge(start.getCityName(), end.getCityName(), weight);

    // Add the new edge to the start city's edges
    startCityEdges.push_back(newEdge);
    cities[start.getCityName()].setEdges(startCityEdges);

    // Update the adjacency list for the start city
    adjacencyList[start.getCityName()].push_back(make_pair(end.getCityName(), weight));

    // Add the reverse edge to the end city's edges
    vector<Edge> endCityEdges = cities[end.getCityName()].getEdges();
    Edge reverseEdge(end.getCityName(), start.getCityName(), weight);
    endCityEdges.push_back(reverseEdge);
    cities[end.getCityName()].setEdges(endCityEdges);
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
    priority_queue<pair<int, pair<string, string>>, vector<pair<int, pair<string, string>>>, greater<pair<int, pair<string, string>>>> pq;

    // Start with an arbitrary city (e.g., the first city)
    string startCity = cities.begin()->first;
    visited.insert(startCity);

    // Add all edges from the start city to the priority queue
    for (const auto& neighbor : adjacencyList.at(startCity)) {
        pq.push(make_pair(neighbor.second, make_pair(startCity, neighbor.first)));
    }

    int totalDistance = 0;
    cout << "Minimum Spanning Tree:" << endl;
    while (!pq.empty() && visited.size() < cities.size()) {
        auto edge = pq.top();
        pq.pop();

        int distance = edge.first;
        string fromCity = edge.second.first;
        string toCity = edge.second.second;

        if (visited.find(toCity) != visited.end()) {
            continue; // Skip if the destination city is already visited
        }

        visited.insert(toCity);
        totalDistance += distance;
        cout << "From: " << fromCity << " to " << toCity << ", Distance: " << distance << endl;

        // Add edges from the newly visited city to the priority queue
        for (const auto& neighbor : adjacencyList.at(toCity)) {
            if (visited.find(neighbor.first) == visited.end()) {
                pq.push(make_pair(neighbor.second, make_pair(toCity, neighbor.first)));
            }
        }
    }

    if (visited.size() < cities.size()) {
        cout << "Graph is not connected. Minimum Spanning Tree not found." << endl;
        return;
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

        // Get neighbors from adjacency list instead of assuming outgoing edges
        if (adjacencyList.find(city) != adjacencyList.end()) {
            for (const auto& neighbor : adjacencyList.at(city)) {
                if (visited.find(neighbor.first) == visited.end()) {
                    q.push(neighbor.first);
                    visited.insert(neighbor.first);
                }
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

            // Check if the city has neighbors before accessing adjacencyList
            if (cities.find(city) != cities.end() && adjacencyList.find(city) != adjacencyList.end()) {
                for (const auto& neighbor : adjacencyList.at(city)) {
                    if (visited.find(neighbor.first) == visited.end()) {
                        s.push(neighbor.first);
                    }
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

    // Display cities and their edges
    cout << "Cities in the graph:" << endl;
    for (const auto& city : cities) {
        cout << city.first << ":" << endl;
        for (const auto& edge : city.second.getEdges()) {
            if (edge.getEndCity() != city.first) {
                cout << "  - " << edge.getEndCity() << " (Weight: " << edge.getWeight() << ")" << endl;
            }
        }
        cout << endl;
    }

    // Visualize the graph
    graphVisualizer::visualize(*this);
}
void Graph::dijkstra(string startCity) {
    if (cities.find(startCity) == cities.end()) {
        cout << "City " << startCity << " does not exist in the graph." << endl;
        return;
    }

    // Initialize distances
    unordered_map<string, int> distance;
    for (const auto& city : cities) {
        distance[city.first] = INT_MAX;
    }
    distance[startCity] = 0;

    // Priority queue to store vertices and their distances
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
    pq.push(make_pair(0, startCity));

    // Process vertices
    while (!pq.empty()) {
        string currentCity = pq.top().second;
        int currentDistance = pq.top().first;
        pq.pop();

        // Visit neighbors
        for (const auto& neighbor : adjacencyList.at(currentCity)) {
            string neighborCity = neighbor.first;
            int weight = neighbor.second;

            // Update distance if shorter path found
            if (currentDistance + weight < distance[neighborCity]) {
                distance[neighborCity] = currentDistance + weight;
                pq.push(make_pair(distance[neighborCity], neighborCity));
            }
        }
    }

    // Output distances
    cout << "Shortest distances from " << startCity << ":" << endl;
    for (const auto& dist : distance) {
        cout << dist.first << ": " << dist.second << endl;
    }
}

