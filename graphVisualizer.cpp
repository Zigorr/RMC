#include "GraphVisualizer.h"
#include <iostream>
#include <iomanip>
using namespace std;

void graphVisualizer::visualize(const Graph& graph) {
    cout << "Graph Visualization:" << endl;

    // Debug output to verify graph data
    cout << "Cities in the graph:" << endl;
    for (const auto& city : graph.getMap()) {
        cout << city.first << ":" << endl;

        // Display edges for the current city
        for (const auto& edge : city.second.getEdges()) {
            cout << "Edge: " << edge.getStartCity() << " <-> " << edge.getEndCity() << " (Weight: " << edge.getWeight() << ")" << endl;
        }

        cout << endl;
    }
}