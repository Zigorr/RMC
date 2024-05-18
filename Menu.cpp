#include<iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include "Menu.h"
#include "City.h"
#include "Graph.h"
#include "Edge.h"

using namespace std;

void Menu::display() {
    int choice;
    string cityname;
    Graph g;
    string filename = "graph_data.txt";
    int indexg = 1;
    unordered_map<int, Graph> graphMap;
 
   graphMap = g.readFromFile(filename);

    do {
        
        cout << "\nMenu:" << endl;
        cout << "1. Add Graph" << endl;
        cout << "2. Display Graph" << endl;
        cout << "3. Update Graph (Add city, Add Edge, Delete city, Delete Edge)" << endl;
        cout << "4. Find and Display Minimum Spanning Tree" << endl;
        cout << "5. Traverse Graph using Breadth First Search" << endl;
        cout << "6. Traverse Graph using Depth First Search" << endl;
        cout << "7. Dijkstra's Algorithm" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        while (!(cin >> choice) || choice < 0 || choice > 7) {
            cout << "Invalid input. Please enter a valid choice: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) {
        case 1: {
            Graph newGraph;
            cout << "Enter the city name: ";
            cin >> cityname;
            City city(cityname);
            newGraph.addCity(city);

            string city2, s;
            do {
                int weight;
                cout << "Enter EndCity: ";
                cin >> city2;
                cout << "Enter edge weight: ";
                while (!(cin >> weight)) {
                    cout << "Invalid input. Please enter a valid weight: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                newGraph.addEdge(cityname, city2, weight);
                cout << "Do you want to add another edge? (yes/no): ";
                cin >> s;
            } while (s == "yes" || s == "Yes");

            graphMap[indexg] = newGraph;
            indexg++;
            break;
        }
        case 2: {
            int graphIndex;
            cout << "Enter the index of Graph you want to display: ";
            while (!(cin >> graphIndex)) {
                cout << "Invalid input. Please enter a valid index: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            if ((graphMap.find(graphIndex) != graphMap.end()))
            {
                graphMap[graphIndex].displayGraphData();
            }
            else {
                cout << "Graph with index " << graphIndex << " does not exist." << endl;
            }
            break;
        }
        case 3: {
            int graphIndex;
            cout << "Enter the index of Graph you want to update: ";
            while (!(cin >> graphIndex)) {
                cout << "Invalid input. Please enter a valid index: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            if (graphMap.find(graphIndex) != graphMap.end()) {
                int updateChoice;
                cout << "1. Add New City" << endl;
                cout << "2. Add New Edge" << endl;
                cout << "3. Delete City" << endl;
                cout << "4. Delete Edge" << endl;
                cout << "Enter your choice: ";
                while (!(cin >> updateChoice) || updateChoice < 1 || updateChoice > 4) {
                    cout << "Invalid input. Please enter a valid choice: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                switch (updateChoice) {
                case 1: {
                    cout << "Enter the city name: ";
                    cin >> cityname;
                    City city(cityname);
                    graphMap[graphIndex].addCity(city);
                    string city2, s;
                    do {
                        int weight;
                        cout << "Enter EndCity : ";
                        cin >> city2;
                        cout << "Enter edge weight: ";
                        cin >> weight;
                        graphMap[graphIndex].addEdge(cityname, city2, weight);
                        cout << "Do you want to add another edge? (yes/no): ";
                        cin >> s;
                    } while (s == "yes" || s == "Yes");
                    break;
                }
                case 2: {
                    string city1, city2, s;
                    do {
                        int weight;
                        cout << "Enter city 1: ";
                        cin >> city1;
                        cout << "Enter city 2: ";
                        cin >> city2;
                        cout << "Enter edge weight: ";
                        cin >> weight;
                        graphMap[graphIndex].addEdge(city1, city2, weight);
                        cout << "Do you want to add another edge? (yes/no): ";
                        cin >> s;
                    } while (s == "yes" || s == "Yes");
                    break;
                }
                case 3: {
                    string city;
                    cout << "Enter the city name to delete: ";
                    cin >> city;
                    graphMap[graphIndex].deleteCity(city);
                    break;
                }
                case 4: {
                    string city1, city2;
                    int weight;
                    cout << "Enter two cities of the edge you want to delete: " << endl;
                    cout << "City 1: ";
                    cin >> city1;
                    cout << "City 2: ";
                    cin >> city2;
                    cout << "Weight: ";
                    cin >> weight;
                    Edge edge(city1, city2, weight);
                    graphMap[graphIndex].deleteEdge(edge);
                    break;
                }
                default:
                    cout << "Invalid choice. Please try again." << endl;
                }
            }
            else {
                cout << "Graph with index " << graphIndex << " does not exist." << endl;
            }
            break;
        }
        case 4: {
            int graphIndex;
            cout << "Enter the index of Graph you want to display: ";
            while (!(cin >> graphIndex)) {
                cout << "Invalid input. Please enter a valid index: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            if (graphMap.find(graphIndex) != graphMap.end()) {
                graphMap[graphIndex].findMST();
            }
            else {
                cout << "Graph with index " << graphIndex << " does not exist." << endl;
            }
            break;
        }
        case 5: {
            int graphIndex;
            cout << "Enter the index of Graph you want to display: ";
            while (!(cin >> graphIndex)) {
                cout << "Invalid input. Please enter a valid index: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            if (graphMap.find(graphIndex) != graphMap.end()) {
                string startCity;
                cout << "Enter starting city for BFS: ";
                cin >> startCity;
                graphMap[graphIndex].BFS(startCity);
            }
            else {
                cout << "Graph with index " << graphIndex << " does not exist." << endl;
            }

            break;
        }
        case 6: {
            int graphIndex;
            cout << "Enter the index of Graph you want to display: ";
            while (!(cin >> graphIndex)) {
                cout << "Invalid input. Please enter a valid index: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            if (graphMap.find(graphIndex) != graphMap.end()) {
                string startCity;
                cout << "Enter starting city for DFS: ";
                cin >> startCity;

                graphMap[graphIndex].DFS(startCity);
            }
            else {
                cout << "Graph with index " << graphIndex << " does not exist." << endl;
            }

            break;
        }
        case 7: {
            int graphIndex;
            cout << "Enter the index of Graph you want to display: ";
            while (!(cin >> graphIndex)) {
                cout << "Invalid input. Please enter a valid index: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            if (graphMap.find(graphIndex) != graphMap.end()) {
                string startCity;
                cout << "Enter starting city for Dijkstra's algorithm: ";
                cin >> startCity;
                graphMap[graphIndex].dijkstra(startCity);
            }
            else {
                cout << "Graph with index " << graphIndex << " does not exist." << endl;
            }
            break;
        }
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
        g.setGraph(graphMap);
    } while (choice != 0);
    g.writeToFile(filename);
}
