#include<iostream>
#include <vector>
#include "Menu.h"
#include "Files.h"
#include "City.h"
#include "Graphh.h"
#include "Edge.h"
#include "City.h"
#include<iostream>
#include<string>

using namespace std;

void Menu::display()
{
    int choice;
    string cityname;
    Graphh g;

    do {
           cout << "\nMenu:" << endl;
        cout << "1. Add City" << endl;
        cout << "2. Add Edge" << endl;
        cout << "3. Delete City" << endl;
        cout << "4. Delete Edge" << endl;
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
            string city2;
            cout << "enter two cities" << endl;
            cin >> city1;
            cin >> city2;

            g.findcity(city1, city2);
        }
        // Add cases for delete city, delete edge, and other options
        case 4:
        {
            string city1;
            string city2;
            cout << "enter two cities of the edge you want to delete" << endl;
            cin >> city1;
            cin >> city2;
            City c1(city1);
            City c2(city1);
            g.deleteEdge(c1,c2);
        }
        case 0:
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
}
