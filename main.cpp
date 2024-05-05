#pragma once
#include <iostream>
#include <vector>
#include "Files.h"
#include "City.h"
#include "Graph.h"
#include"Edge.h"
#include <list>
#include <unordered_map>
#include "Menu.h"
using namespace std;
int main() {
    
   //// Create an instance of the Files class
   // vector<City> cities;
   // Files fileH;
   // City c("cairo");
   // City c1("alex");
   // City c2("zft");

   //// Read lines from input file "input.txt"

   // string inputFilename = "input.txt";
   // vector<string> lines = fileH.readLines(inputFilename);

   //// Display lines read from input file

   // cout << "Lines read from " << inputFilename << ":" << endl;
   // for (const string& line : lines) {
   //     cout << line << endl;
   // }

   //// Write lines to output file "output.txt"
   //
   // string outputFilename = "output.txt";
   // fileH.writeCity(cities);
   // 

   // cout << "Lines written to " << outputFilename << " successfully." << endl;
    City c;
    City c1;
    vector<City> cities;
    Menu m;

    m.display();
    
    return 0;
}
   
