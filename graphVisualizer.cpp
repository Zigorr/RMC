#include "GraphVisualizer.h"
#include <iostream>
#include <iomanip>
using namespace std;

void graphVisualizer::visualize(const Graph& graph) {
    cout << "Graph Visualization:" << endl;
    for (const auto& city : graph.getMap()) {
        cout << city.first << ":" << endl;
        for (const auto& edge : city.second.getEdges()) {
            cout << "  - " << edge.getEndCity() << " (Weight: " << edge.getWeight() << ")" << endl;
        }
    }
}
