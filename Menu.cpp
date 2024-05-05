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
        cout << "1. Add City" << endl;
        cout << "2. Add Edge" << endl;
        cout << "3. Delete City" << endl;
        cout << "4. Delete Edge" << endl;
        cout << "5. Find City" << endl;
        cout << "6. Display Graph Data" << endl;
        cout << "7. Find and Display Minimum Spanning Tree" << endl;
        cout << "8. Traverse Graph using Breadth First Search" << endl;
        cout << "9. Traverse Graph using Depth First Search" << endl;
           cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1 : {
            cout << "Enter the city name" << endl;
            cin >> cityname;
            City c(cityname);
            g.addCity(c);
            break;
        }
        case 2 : {
            // Code to add an edge
            string city1, city2,s;
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
        case 3 :
        {
            string city1;
            cout << "enter city" << endl;
            cin >> city1;
            City c(city1);
            g.deleteCity(c);
            break;
        }
        // Add cases for delete city, delete edge, and other options
        case 4:
        {
            string city1;
            string city2;
            int weight;
            cout << "enter two cities of the edge you want to delete" << endl;
            cin >> city1;
            cin >> city2;
            cin >> weight;
            Edge e(city1, city2, weight);
            g.deleteEdge(e);
            break;
        }
        case 5:
        {
            string city1;
            string city2;
            cout << "enter two cities" << endl;
            cin >> city1;
            cin >> city2;

            g.findCity(city1, city2);
        }
        case 6: {
            g.displayGraphData();
            break;
        }
        case 7: {
            g.findMST();
            break;
        }
        case 8: {
            string startCity;
            cout << "Enter starting city for BFS:" << endl;
            cin >> startCity;
            g.BFS(startCity);
            break;
        }
        case 9: {
            string startCity;
            cout << "Enter starting city for DFS:" << endl;
            cin >> startCity;
            g.DFS(startCity);
            break;
        }
        case 0:
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
   
}
