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

void Graphh::deleteCity(City city)
{

}

void Graphh::deleteEdge(City start, City end)
{
    vector<Edge>::iterator it;
    v = c.getedges();

    int i = 1;
    int q = 1;
    int answer;

    for (it = v.begin(); it != v.end(); it++)
    {
        cout << i << " Start : " << it->getstartcity() << " -> " << " ( End : " << it->getendcity() << " , Weight  " << it->getweight() << " ) -> " << endl;
        i++;
    }

    cout << endl <<"Which Edge do you want to delete " << endl;
    cin >> answer;
    // Deleting edge//arr[alex]=cairo
    if (answer > 0 && answer <= v.size())
    {
        v.erase(v.begin() + answer - 1);
        // Displaying remaining edges
        int q = 1;
        for (it = v.begin(); it != v.end(); it++) {
            cout << q << " Start : " << it->getstartcity() << " -> " << " ( End : " << it->getendcity() << " , Weight  " << it->getweight() << " ) -> "<<endl;
            q++;
        }
    }
    else 
    {
        cout << "Invalid edge number." << endl;
    }
}