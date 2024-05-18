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
 

    Menu m;
    Graph myGraph;
    std::string filename = "graph_data.txt";

    // Load graph data at the start
    myGraph.loadGraphFromFile(filename);

    // Your application logic here (including the menu system)

    // Save graph data before exiting
    myGraph.saveGraphToFile(filename);
    m.display();
    
    return 0;
}
   
