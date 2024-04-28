#include "City.h"
#include <string>
#include <list>
#include<iostream>
#include <unordered_map>
using namespace std;
City::City(string cityName)  
{
    name = cityName;
}

City::City(string cityName, string city1Name)
{
    city1Name;
    cityName;
}

City::City()
{
    name = "NULL";
}

bool City::findcity()
{

    return false;
}

string City::getName()
{
    return name;
}

void City::addcity()
{
    string cityName;
    Edge e;
    cout << "Enter the city Name :  ";
    cin >> cityName;
    City z(cityName);
    cities.push_back(cityName);
   // e.dis.insert();
}
