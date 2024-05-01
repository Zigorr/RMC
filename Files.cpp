#pragma once
#include "Files.h"
#include"City.h"
#include"Edge.h"
#include<iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
vector<Edge> v;
using namespace std;

////Files::Files(const string & filename) {
////    fileStream.open(filename);
////    if (!fileStream.is_open()) {
////       cerr << "Error: Could not open file " << filename <<endl;
////    }
////}
//void Files::writeCity(vector<City> cities) {
//    if (fileStream.is_open()) {
//        for (auto& city : cities) { // Iterate over each City object in the vector
//            fileStream << "City: " << city.getName() << endl; // Write city name to file
//        }
//        fileStream.close(); // Close file after writing all cities
//    }
//    else {
//        cerr << "Error: File is not open for writing" << endl;
//    }
//}
//
//
//
//vector<string> Files::readLines(const string& filename)
//{
//    vector<string> lines;  // Create a vector of strings to store the lines read from the file
//    ifstream fileStr(filename);  // Open the file for reading
//
//    if (!fileStr.is_open()) {
//        cerr << "Error: Could not open file " << filename << std::endl;
//        return lines;  // Return empty vector if file cannot be opened
//    }
//
//    string line;  // Declare a string variable to hold each line read from the file
//
//    // Loop to read lines from the file using getline
//    while (getline(fileStr, line)) {
//        lines.push_back(line);  // Add the current line to the vector of strings
//    }
//
//    fileStr.close();  // Close the file after reading
//
//    return lines;  // Return the vector containing all the lines read from the file
//}
//
//template<class T>
//void Files<T>::writeVectorToFile(const vector<Edge>& vec, const string& filename) {
//    ofstream outFile(filename);
//    if (!outFile.is_open()) {
//        cerr << "Error: Couldn't open file for writing." << endl;
//        return;
//    }
//
//    for (const auto& edge : vec) {
//        outFile << edge.getstartcity() << endl;
//        outFile << edge.getendcity() << endl;
//        outFile << edge.getweight() << endl;
//    }
//
//    outFile.close();
//}
template<class T>
void Files<T>::writeMapoFile(unordered_map<string, City>& cities, const string& filename)
{
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Error: Couldn't open file for writing." << endl;
        return;
    }

    for (const auto& pair : cities) {
        outFile << "Start City: " << pair.first << endl;
        const City& city = pair.second;
        const vector<Edge>& edges = city.getEdges();
        for (const auto& edge : edges) {
            outFile << "End City: " << edge.getEndCity() << ", Weight: " << edge.getWeight() << endl;
        }
    }

    outFile.close();
}
template<class T>
unordered_map<string, City> Files<T>::readMapFromFile(const string& filename) {
    unordered_map<string, City> map;
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "Error: Couldn't open file for reading." << endl;
        return map;
    }
    string startCity, endCity;
    int weight;

    City c;
    v = c.getedges();

}
   


