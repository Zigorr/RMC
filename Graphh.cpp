#include "Graphh.h"
#include "Menu.h"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Menu.h"
#include "City.h"
using namespace std;
vector<Edge> v;// temp vector
City c;
void Graphh::addCity(City city)
{
    if (cities.find(city.getcityname()) != cities.end())
    {
        cout << "City already exits" << endl;
    }
    else
    {
        cities[city.getcityname()] = {}; //Initialize with an empty vector of edges
        cout << city.getcityname() << " added successfully" << endl;
    }

}
void Graphh::findcity(string start, string end)
{
    vector<Edge>temp;
    v = c.getedges();
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
void Graphh::addEdge(City start, City end, int weight)
{
        City c1(start); // ll constructor
        City c2(end);
       
        findcity(c1.getcityname(), c2.getcityname());

        Edge e(start.getcityname(), end.getcityname(), weight);
        Edge e1(end.getcityname(), start.getcityname(), weight);

        v = c.getedges(); // v = edges

        v.push_back(e);
        v.push_back(e1);

        c.setedges(v); // brg3 fy fy edges 

        cities[c1.getcityname()] = { {c2} };
        cities[c2.getcityname()] = { {c1} };

        vector<Edge>::iterator it;
        for (it = v.begin(); it != v.end(); it++)
        {
            cout << "Start: " << it->getstartcity() << ", End: " << it->getendcity() << ", Weight: " << it->getweight() << endl;
        }
}

void Graphh::deleteCity(City city) {
    bool cityDeleted = false; 
    vector<Edge> temp;
    v = c.getedges(); 
    for (auto it = v.begin(); it != v.end(); ++it) {
        if ((it->getstartcity() != c.getcityname()) && (it->getendcity() != c.getcityname()))
        {
            temp.push_back(*it);
        }
        else 
        {
            cityDeleted = true;
        }
    }
    if (cityDeleted) {
        cout << "City deleted successfully." << endl;
        v = temp;
    }
    else {
        cout << "City with the specified details not found." << endl;
    }
    cout << "Remaining edges:" << endl;
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << " Start : " << it->getstartcity() << " -> "
            << " ( End : " << it->getendcity() << " , Weight  " << it->getweight() << " ) -> " << endl;
    }
    c.setedges(temp);
}

void Graphh::deleteEdge(Edge e)
{
    vector<Edge>temp;
    v = c.getedges();
   /* string start = e.getstartcity();
    string end = e.getendcity();
    int weight = e.getweight();*/

    bool edgeDeleted = false; // Flag to track if any edge was deleted
    //125
    for (auto it = v.begin(); it != v.end(); ++it) {
        if (((it->getstartcity() != e.getstartcity() && it->getendcity() != e.getendcity() && it->getweight() != e.getweight()) ||(it->getstartcity() != e.getendcity() && it->getendcity() != e.getstartcity() && it->getweight() != e.getweight()))) {
            temp.push_back(*it);
        }
        else {
            edgeDeleted = true;
        }
    }
    if (edgeDeleted) {
        cout << "Edge deleted successfully." << endl;
        v = temp;
    }
    else
    {
        cout << "Edge with the specified details not found." << endl;
    }
    cout << "Remaining edges:" << endl;
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << " Start : " << it->getstartcity() << " -> " << " ( End : " << it->getendcity() << " , Weight  " << it->getweight() << " ) -> " << endl;
    }
    c.setedges(temp);
    
}

//    
//        vector<Edge>::iterator it;
//        v = c.getedges();
//
//        int i = 1;
//        int answer;
//// if (it->getstartcity() == start.getcityname() && it->getendcity() == end.getcityname()) {
//        // Displaying edges and checking for deletion
//        for (it = v.begin(); it != v.end(); it++) 
//        {   
//                cout << " ( " << i  << it->getstartcity() << " -> " <<  it->getendcity() << it->getweight() << " ) -> " << endl;
//            i++;
//        }
//
//        cout << endl << "Which Edge do you want to delete: ";
//        cin >> answer;
//
//        // Deleting edge
//        if (answer > 0 && answer <= v.size()) {
//            // Finding the edge to delete
//            it = v.begin();
//            int count = 1;
//            for (auto it = v.begin(); it != v.end(); ) {
//                if (it->getstartcity() == start.getcityname() && it->getendcity() == end.getcityname()) {
//                    // Erase the edge from the vector
//                    v.erase(it);
//                }
//                else {
//                    ++it; //
//                }
//                if (it->getstartcity() == end.getcityname() && it->getendcity() == start.getcityname()) {
//                    // Erase the edge from the vector
//                    v.erase(it);
//                }
//                else {
//                    ++it; // Move to the next edge
//                }
//            }
//
//
//
//
//            // Displaying remaining edges
//            int q = 1;
//            for (it = v.begin(); it != v.end(); it++) {
//                cout << " ( " << i << it->getstartcity() << " -> " << it->getendcity() << it->getweight() << " ) -> " << endl;
//                q++;
//            }
//        }
//        else {
//            cout << "Invalid edge number." << endl;
//        }
//    }
//void Graphh::deleteEdge(const string& startCity, const string& endCity) {
//{
//    //vector<Edge>::iterator it;
//    //v = c.getedges();
//
//    //int i = 1;
//    //int q = 1;
//    //int answer;
//
//    //for (it = v.begin(); it != v.end(); it++)
//    //{
//    //    cout << i << " Start : " << it->getstartcity() << " -> " << " ( End : " << it->getendcity() << " , Weight  " << it->getweight() << " ) -> " << endl;
//    //    i++;
//    //}
//
//    //    //cities.at(start.getcityname());
//    //    //cities.at(end.getcityname());
//
//    //cout << endl << "Which Edge do you want to delete " << endl;
//    //cin >> answer;
//    //
//    //// Deleting edge//arr[alex]=cairo
//    //if (answer > 0 && answer <= v.size())
//    //{
//    //    
//    //    v.erase(v.begin() + answer - 1);
//    //    // Displaying remaining edges
//    //    int q = 1;
//    //    for (it = v.begin(); it != v.end(); it++) {
//    //        cout << q << " Start : " << it->getstartcity() << " -> " << " ( End : " << it->getendcity() << " , Weight  " << it->getweight() << " ) -> " << endl;
//    //        q++;
//    //    }
//    //}
//    //else
//    //{
//    //    cout << "Invalid edge number." << endl;
//    //}
//   
//    
//}