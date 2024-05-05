#include<iostream>
#include <vector>
#include "Menu.h"
#include "Files.h"
#include "City.h"
#include "Graph.h"
#include "Edge.h"
#include "City.h"
#include<iostream>
#include<string>
#include "Files.cpp"

using namespace std;

void Menu::display()
{
    int choice;
    string cityname;
    /*  Files f;*/
    Graph g;
    //string filename = "Map.txt"; // Specify the filename

     //f.readVectorFromFile(filename);

    // Now you can use the 'cities' map to access the data read from the file
    // For example:
   /* for (const auto& pair : cities) {
        cout << "City: " << pair.first << ", Population: " << pair.second.getPopulation() << endl;
    }*/

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Add Graph" << endl;
        cout << "2. Display Graph" << endl;
        cout << "3. Update Graph" << endl;
        cout << "4. Find and Display Minimum Spanning Tree" << endl;
        cout << "5. Traverse Graph using Breadth First Search" << endl;
        cout << "6. Traverse Graph using Depth First Search" << endl;
        cout << "7. Dijkstra's Algorithm" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
        {
            int answer;
            cout << "1. Add City" << endl;
            cout << "2. Add Edge" << endl;
            cin >> answer;
            switch (answer) {
            case 1:
            {
                cout << "Enter the city name" << endl;
                cin >> cityname;
                City c(cityname);
                g.addCity(c);
                break;
            }
            case 2:
            {
                string city1, city2, s;
                do
                {
                    int weight;
                    cout << "Enter city 1: ";
                    cin >> city1;
                    cout << "Enter city 2: ";
                    cin >> city2;
                    cout << "Enter edge weight: ";
                    cin >> weight;
                    // Add the edge to the graph
                    g.addEdge(city1, city2, weight);
                    cout << "Do you want to add another edge:" << endl;
                    cin >> s;
                } while (s == "yes" || s == "Yes");
                break;
            }
            }
            break;
        }
        case 2: {
            g.displayGraphData();
            break;
        }
        case 3:
        {
            int answer;
            cout << "1. Add New City" << endl;
            cout << "2. Add New Edge" << endl;
            cout << "3. Delete City" << endl;
            cout << "4. Delete Edge" << endl;
            cin >> answer;
            switch (answer) {
            case 1:
            {
                cout << "Enter the city name" << endl;
                cin >> cityname;
                City c(cityname);
                g.addCity(c);
                break;
            }
            case 2:
            {
                string city1, city2, s;
                do
                {
                    int weight;
                    cout << "Enter city 1: ";
                    cin >> city1;
                    cout << "Enter city 2: ";
                    cin >> city2;
                    cout << "Enter edge weight: ";
                    cin >> weight;
                    // Add the edge to the graph
                    g.addEdge(city1, city2, weight);
                    cout << "Do you want to add another edge:" << endl;
                    cin >> s;
                } while (s == "yes" || s == "Yes");
                break;
            }
            case 3:
            {
                string city1;
                cout << "enter city" << endl;
                cin >> city1;
                City c(city1);
                g.deleteCity(c);
                break;
            }
            case 4:
            {
                string city1;
                string city2;
                int weight;
                cout << "enter two cities of the edge you want to delete" << endl;
                cout << "City 1: ";
                cin >> city1;
                cout << "City 2: ";
                cin >> city2;
                cout << "Weight: ";
                cin >> weight;
                Edge e(city1, city2, weight);
                g.deleteEdge(e);
                break;
            }
            }
            break;
        }
        case 4:
        {
            g.findMST();
            break;
        }
        case 5:
        {
            string startCity;
            cout << "Enter starting city for BFS:" << endl;
            cin >> startCity;
            g.BFS(startCity);
            break;
        }
        case 6: {
            string startCity;
            cout << "Enter starting city for DFS:" << endl;
            cin >> startCity;
            g.DFS(startCity);
            break;
        }
        case 7: {
            string startCity;
            cout << "Enter starting city for Dijkstra's algorithm:" << endl;
            cin >> startCity;
            g.dijkstra(startCity);
            break;
        }
        case 0:
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

}