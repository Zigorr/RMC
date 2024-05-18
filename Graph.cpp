#include "Graph.h"
#include "Menu.h"
#include "Menu.h"
#include "City.h"
#include "GraphVisualizer.h"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
#include <unordered_set>
#include <queue>
#include <sstream>
#include <fstream>
using namespace std;
vector<Edge> v;// temp vector
City c;
unordered_map<string, City> Graph::getMap()
{
    return unordered_map<string, City>();
}
unordered_map<int, Graph> Graph::getGraph()
{
    return graphs;
}
void Graph::setGraph(unordered_map<int, Graph> graph)
{
    graphs = graph;
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
    if (cities.find(start.getCityName()) == cities.end())
    {
        // cout << start.getCityName() <<" added to the map" << endl;
        addCity(start);
    }
    if (cities.find(end.getCityName()) == cities.end())
    {
        // cout << end.getCityName() << "  added to the map" << endl;
        addCity(end);
    }
    // Check if start and end cities exist in the graph, add them if they don't
   /* findCity(start.getCityName(), end.getCityName());*/

   // Retrieve the edges of the start city

    vector<Edge> startCityEdges = cities[start.getCityName()].getEdges();

    // Create the new edge

    Edge newEdge(start.getCityName(), end.getCityName(), weight);

    // Add the new edge to the start city's edges

    startCityEdges.push_back(newEdge);
    cities[start.getCityName()].setEdges(startCityEdges);

    vector<Edge> endCityEdges = cities[end.getCityName()].getEdges();

    // Create the new edge

    Edge reverseEdge(end.getCityName(), start.getCityName(), weight);

    // Add the reverse edge to the end city's edges

    endCityEdges.push_back(reverseEdge);
    cities[end.getCityName()].setEdges(endCityEdges);

    // Output the edges for verification

    cout << "Edges after adding new edge:" << endl;

    for (auto city : cities)
    {
        vector<Edge> edges = city.second.getEdges();
        for (auto edge : edges)
        {
            cout << "Start: " << edge.getStartCity() << ", End: " << edge.getEndCity() << ", Weight: " << edge.getWeight() << endl;
        }
    }
}
void Graph::deleteCity(string cityName)
{
    if (cities.find(cityName) != cities.end())
    {
        // Remove the city from the graph
        cities.erase(cityName);

        // Iterate over all cities
        for (auto& cityEntry : cities)
        {
            vector<Edge> edges = cityEntry.second.getEdges();
            vector<Edge> tempEdges;

            // Iterate over edges of the current city
            for (auto& edge : edges)
            {
                // Check if the edge does not contain the deleted city
                if (edge.getStartCity() != cityName && edge.getEndCity() != cityName)
                {
                    // Add the edge to tempEdges if it does not contain the deleted city
                    tempEdges.push_back(edge);
                }
            }

            // Update the edges of the current city
            cityEntry.second.setEdges(tempEdges);
        }

        cout << "City " << cityName << " deleted successfully." << endl;
    }
    else
    {
        cout << "City not found in the graph." << endl;
    }
}
void Graph::deleteEdge(Edge e)
{
    bool edgeDeleted = false;

    // Iterate over all cities
    for (auto& cityEntry : cities)
    {
        // Get reference to the city
        City& city = cityEntry.second;

        // Get reference to the city's edges
        vector<Edge> edges = city.getEdges();
        vector<Edge> tempEdges;

        // Iterate over edges of the current city
        for (auto& edge : edges)
        {
            // Check if the edge does not match the specified edge (e)
            if (!((edge.getStartCity() == e.getStartCity() && edge.getEndCity() == e.getEndCity() && edge.getWeight() == e.getWeight()) || (edge.getStartCity() == e.getEndCity() && edge.getEndCity() == e.getStartCity() && edge.getWeight() == e.getWeight())))
            {
                // Add the edge to tempEdges if it does not match the specified edge
                tempEdges.push_back(edge);
            }
            else
            {
                // Set edgeDeleted to true if the edge is found and removed
                edgeDeleted = true;
            }
        }

        // Update the edges of the current city
        city.setEdges(tempEdges);

        for (auto remainingEdge : tempEdges)
        {
            cout << "Start: " << remainingEdge.getStartCity() << ", End: " << remainingEdge.getEndCity() << ", Weight: " << remainingEdge.getWeight() << endl;
        }
    }

    if (!edgeDeleted)
    {
        cout << "Edge with the specified details not found in any city." << endl;
    }
}
void Graph::findMST() {
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
    for (auto edge : cities[startCity].getEdges())
        pq.push(make_pair(edge.getWeight(), make_pair(startCity, edge.getEndCity())));

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
        for (auto edge : cities[toCity].getEdges()) {
            if (visited.find(edge.getEndCity()) == visited.end()) {
                pq.push(make_pair(edge.getWeight(), make_pair(toCity, edge.getEndCity())));
            }
        }
    }

    if (visited.size() < cities.size()) {
        cout << "Graph is not connected. Minimum Spanning Tree not found." << endl;
        return;
    }

    cout << "Total Distance of Minimum Spanning Tree: " << totalDistance << endl;
}
void Graph::BFS(string startCity) {
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

        // Get neighbors from the vector of edges of the current city
        for (auto edge : cities[city].getEdges()) {
            string neighbor = edge.getEndCity();
            if (visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }
    cout << endl;
}
void Graph::DFS(string startCity) {
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

            // Get neighbors from the vector of edges of the current city
            for (auto edge : cities[city].getEdges()) {
                string neighbor = edge.getEndCity();
                if (visited.find(neighbor) == visited.end()) {
                    s.push(neighbor);
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
    cout << "Cities in the graph:" << endl;
    for (auto city : cities) {
        cout << city.first << ":" << endl;
        for (auto edge : city.second.getEdges()) {
            if (edge.getEndCity() != city.first) {
                cout << "  - " << edge.getEndCity() << " (Weight: " << edge.getWeight() << ")" << endl;
            }
        }
        cout << endl;
    }
}
void Graph::dijkstra(string startCity) {
    if (cities.find(startCity) == cities.end()) {
        cout << "City " << startCity << " does not exist in the graph." << endl;
        return;
    }

    // Initialize distances
    unordered_map<string, int> distance;
    for (auto city : cities) {
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
        for (auto edge : cities[currentCity].getEdges()) {
            string neighborCity = edge.getEndCity();
            int weight = edge.getWeight();

            // Update distance if shorter path found
            if (currentDistance + weight < distance[neighborCity]) {
                distance[neighborCity] = currentDistance + weight;
                pq.push(make_pair(distance[neighborCity], neighborCity));
            }
        }
    }
    // Output distances
    cout << "Shortest distances from " << startCity << ":" << endl;
    for (auto dist : distance) {
        if (dist.second == INT_MAX) {
            cout << "No path from " << startCity << " to " << dist.first << endl;
        }
        else
        {
            cout << dist.first << ": " << dist.second << endl;
        }
    }
}
//void Graph::writeToFile(const std::string& filename) const {
//    std::ofstream file(filename);
//    if (file.is_open()) {
//        for (const auto& graphPair : graphs) {
//            int graphIndex = graphPair.first;
//            const Graph& graph = graphPair.second;
//
//            std::cout << "Writing Graph " << graphIndex << " to file..." << std::endl;
//            file << graphIndex << std::endl;
//
//            for (const auto& cityPair : graph.getCities()) {
//                const City& city = cityPair.second;
//                file << city.getCityName() << std::endl;
//
//                const auto& edges = city.getEdges();
//                file << edges.size() << std::endl;
//                for (const auto& edge : edges) {
//                    file << edge.getStartCity() << std::endl
//                        << edge.getEndCity() << std::endl
//                        << edge.getWeight() << std::endl;
//                }
//                file << std::endl; // Add empty line to separate each city's data
//            }
//        }
//        file.close();
//        std::cout << "Graph data written to file: " << filename << std::endl;
//    }
//    else {
//        std::cout << "Unable to open file: " << filename << std::endl;
//    }
//}
//
//std::unordered_map<int, Graph> Graph::readFromFile(const std::string& filename) {
//    std::ifstream file(filename);
//    if (!file.is_open()) {
//        std::cout << "Unable to open file: " << filename << std::endl;
//        return {}; // Return an empty map on failure to open file
//    }
//
//    std::unordered_map<int, Graph> graphs; // Create a local map to hold the graph data
//    int graphIndex;
//    while (file >> graphIndex) {
//        Graph currentGraph;
//        std::string cityName;
//
//        // To consume the newline character after the graph index
//        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//
//        while (std::getline(file, cityName)) {
//            if (cityName.empty()) {
//                break; // Stop if we find an empty line indicating the end of city data for this graph
//            }
//
//            City currentCity;
//            currentCity.setCityName(cityName);
//
//            int edgeCount;
//            file >> edgeCount;
//
//            // To consume the newline character after the edge count
//            file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//
//            for (int i = 0; i < edgeCount; ++i) {
//                std::string startCity, endCity;
//                int weight;
//
//                std::getline(file, startCity);
//                std::getline(file, endCity);
//                file >> weight;
//
//                // To consume the newline character after the weight
//                file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//
//                Edge edge(startCity, endCity, weight);
//                currentCity.getEdges().push_back(edge);
//            }
//
//            currentGraph.addCity(currentCity);
//        }
//        graphs[graphIndex] = currentGraph;
//    }
//    file.close();
//    std::cout << "Graph data read from file: " << filename << std::endl;
//    return graphs; // Return the map of graphs
//}


