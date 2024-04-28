#include "Files.h"
#include<iostream>
#include <fstream>
#include <string>
using namespace std;

//Files::Files(const string & filename) {
//    fileStream.open(filename);
//    if (!fileStream.is_open()) {
//       cerr << "Error: Could not open file " << filename <<endl;
//    }
//}
void Files::writeCity(vector<City> cities) {
    if (fileStream.is_open()) {
        for (auto& city : cities) { // Iterate over each City object in the vector
            fileStream << "City: " << city.getName() << endl; // Write city name to file
        }
        fileStream.close(); // Close file after writing all cities
    }
    else {
        cerr << "Error: File is not open for writing" << endl;
    }
}



vector<string> Files::readLines(const string& filename)
{
    vector<string> lines;  // Create a vector of strings to store the lines read from the file
    ifstream fileStr(filename);  // Open the file for reading

    if (!fileStr.is_open()) {
        cerr << "Error: Could not open file " << filename << std::endl;
        return lines;  // Return empty vector if file cannot be opened
    }

    string line;  // Declare a string variable to hold each line read from the file

    // Loop to read lines from the file using getline
    while (getline(fileStr, line)) {
        lines.push_back(line);  // Add the current line to the vector of strings
    }

    fileStr.close();  // Close the file after reading

    return lines;  // Return the vector containing all the lines read from the file
}

