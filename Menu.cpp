#include <iostream>
#include <vector>
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
    vector<Graph> graphList;
    g.loadGraphFromFile(filename);
    graphList = g.getGraphs();

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Add Graph" << endl;
        cout << "2. Display Graph" << endl;
        cout << "3. Update Graph (Add city, Add Edge, Delete city, Delete Edge)" << endl;
        cout << "4. Find and Display Minimum Spanning Tree" << endl;
        cout << "5. Traverse Graph using Breadth First Search" << endl;
        cout << "6. Traverse Graph using Depth First Search" << endl;
        cout << "7. Dijkstra's Algorithm" << endl;
        cout << "8. Graph Visualization" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        while (!(cin >> choice) || choice < 0 || choice > 8) {
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

            graphList.push_back(newGraph);
            break;
        }
        case 2: {
            int graphIndex;
            cout << "Enter the index of Graph you want to display: ";
            while (!(cin >> graphIndex) || graphIndex < 1 || graphIndex > graphList.size()) {
                cout << "Invalid input. Please enter a valid index: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            graphList[graphIndex - 1].displayGraphData();
            break;
        }
        case 3: {
            int graphIndex;
            cout << "Enter the index of Graph you want to update: ";
            while (!(cin >> graphIndex) || graphIndex < 1 || graphIndex > graphList.size()) {
                cout << "Invalid input. Please enter a valid index: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

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
                graphList[graphIndex - 1].addCity(city);
                string city2, s;
                do {
                    int weight;
                    cout << "Enter EndCity : ";
                    cin >> city2;
                    cout << "Enter edge weight: ";
                    cin >> weight;
                    graphList[graphIndex - 1].addEdge(cityname, city2, weight);
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
                    graphList[graphIndex - 1].addEdge(city1, city2, weight);
                    cout << "Do you want to add another edge? (yes/no): ";
                    cin >> s;
                } while (s == "yes" || s == "Yes");
                break;
            }
            case 3: {
                string city;
                cout << "Enter the city name to delete: ";
                cin >> city;
                graphList[graphIndex - 1].deleteCity(city);
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
                graphList[graphIndex - 1].deleteEdge(edge);
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
            }
            break;
        }
        case 4: {
            int graphIndex;
            cout << "Enter the index of Graph to get its minimum spanning tree: ";
            while (!(cin >> graphIndex) || graphIndex < 1 || graphIndex > graphList.size()) {
                cout << "Invalid input. Please enter a valid index: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            graphList[graphIndex - 1].findMST();
            break;
        }
        case 5: {
            int graphIndex;
            cout << "Enter the index of Graph to traverse using BFS: ";
            while (!(cin >> graphIndex) || graphIndex < 1 || graphIndex > graphList.size()) {
                cout << "Invalid input. Please enter a valid index: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            string startCity;
            cout << "Enter starting city for BFS: ";
            cin >> startCity;
            graphList[graphIndex - 1].BFS(startCity);
            break;
        }
        case 6: {
            int graphIndex;
            cout << "Enter the index of Graph you want to traverse using DFS: ";
            while (!(cin >> graphIndex) || graphIndex < 1 || graphIndex > graphList.size()) {
                cout << "Invalid input. Please enter a valid index: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            string startCity;
            cout << "Enter starting city for DFS: ";
            cin >> startCity;
            graphList[graphIndex - 1].DFS(startCity);
            break;
        }
        case 7: {
            int graphIndex;
            cout << "Enter the index of Graph you want to apply dijkstra's algorithm to: ";
            while (!(cin >> graphIndex) || graphIndex < 1 || graphIndex > graphList.size()) {
                cout << "Invalid input. Please enter a valid index: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            string startCity;
            cout << "Enter starting city for Dijkstra's algorithm: ";
            cin >> startCity;
            graphList[graphIndex - 1].dijkstra(startCity);
            break;
        }
        case 8:
        {
            int graphIndex;
            cout << "Enter the index of Graph you want to visualize: ";
            while (!(cin >> graphIndex) || graphIndex < 1 || graphIndex > graphList.size()) {
                cout << "Invalid input. Please enter a valid index: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            graphList[graphIndex - 1].generateDotFile("graph.dot");
            break;
        }
        case 0:
            cout << "Exiting program." << endl;

            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
    g.setGraphs(graphList);
    g.saveGraphToFile(filename);
}