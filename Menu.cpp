#include<iostream>
#include <vector>
#include "Menu.h"
#include "Files.h"
#include "City.h"
#include "Graphh.h"
#include<iostream>
using namespace std;
void Menu::display()
{
		cout << " \n Menu:" << endl;
		cout << "1. Add City" << endl;
		cout << "2. Add Edge" << endl;
		cout << "3. Delete City" << endl;
		cout << "4. Delete Edge" << endl;
		// ... other options
		cout << "0. Exit" << endl;
        
    //  do {
    //    cin >> choice;

    //    switch (choice) {
    //    case 1: {
    //        // Code to add a city
    //        string cityName;
    //        cout << "Enter city name: ";
    //        cin >> cityName;
    //        Graphh.addCity(cityName);
    //        break;
    //    }
    //    case 2: {
    //        // Code to add an edge
    //        string city1, city2;
    //        int weight;
    //        cout << "Enter city 1: ";
    //        cin >> city1;
    //        cout << "Enter city 2: ";
    //        cin >> city2;
    //        cout << "Enter edge weight: ";
    //        cin >> weight;
    //        Graphh.addEdge(city1, city2, weight);
    //        break;
    //    }
    //          // ... other options based on your menu
    //    case 0:
    //        cout << "Exiting program..." << endl;
    //        break;
    //    default:
    //        cout << "Invalid choice. Please try again." << endl;
    //    }
    //} while (choice != 0)
}
