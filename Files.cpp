//#pragma once
//#include "Files.h"
//#include"City.h"
//#include"Edge.h"
//#include"Graphh.h"
//#include<iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <unordered_map>
//vector<Edge> v;
//using namespace std;
//////Files::Files(const string & filename) {
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
//
//void Files:: writeVectorToFile(vector<Edge> edges,  string filename) 
//{
//    ofstream outFile(filename); // Open the file for writing
//    if (!outFile.is_open())
//    {
//        cerr << "Error: Couldn't open file for writing." << endl;
//        return;
//    }
//
//    // Write each element of the vector to the file
//  /*  vector<Edge>::iterator it;*/
//    for (auto& edge : edges) 
//    {
//        outFile << edge.getstartcity() << " " << edge.getendcity() << " " << edge.getweight()<<endl;
//    }
//
//    outFile.close(); // Close the file
//}
//void Files::writeVectorToFile(vector<Edge> edges,  string filename)
//{
//    ofstream outFile(filename); // Open the file for writing
//    if (!outFile.is_open())
//    {
//        cerr << "Error: Couldn't open file for writing." << endl;
//        return;
//    }
//
//    // Write each element of the vector to the file
//  /*  vector<Edge>::iterator it;*/
//    for (auto& edge : edges)
//    {
//        outFile << edge.getstartcity() << " " << edge.getendcity() << " " << edge.getweight() << endl;
//    }
//
//    outFile.close(); // Close the file
//}
//vector<Edge> Files::readVectorFromFile( string filename)
//{
//    vector<Edge> edges; // Vector to store read edges
//    ifstream inFile(filename); // Open the file for reading
//    if (!inFile.is_open())
//    {
//        cerr << "Error: Couldn't open file for reading." << endl;
//        return edges; // Return empty vector
//    }
//
//    string startCity, endCity;
//    int weight;
//    while (inFile >> startCity >> endCity >> weight)
//    {
//        edges.push_back(Edge(startCity, endCity, weight)); // Create Edge object and add to vector
//    }
//
//    inFile.close(); // Close the file
//    return edges;
//}



   


