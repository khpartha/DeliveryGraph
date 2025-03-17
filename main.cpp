#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <limits>
#include <stdexcept>
#include <string>
#include <algorithm>
#include "Graph.cpp"

using namespace std;

 

int main() {
    DeliveryGraph graph;

    // Create several delivery locations.
    // Each location is defined as { id, timeWindowStart, timeWindowEnd, demand }
    graph.addLocation({"A", 8, 12, 5});
    graph.addLocation({"B", 9, 13, 3});
    graph.addLocation({"C", 10, 15, 4});
    graph.addLocation({"D", 7, 11, 2});
    graph.addLocation({"E", 8, 14, 6});

    // Define roads between locations with travel times (for example, in minutes)
    graph.addEdge("A", "B", 10);
    graph.addEdge("A", "C", 20);
    graph.addEdge("B", "C", 5);
    graph.addEdge("B", "D", 15);
    graph.addEdge("C", "D", 10);
    graph.addEdge("C", "E", 15);
    graph.addEdge("D", "E", 5);

    try {
        // Calculate the fastest route from location A to E.
        vector<string> route = graph.shortestPath("A", "E");
        cout << "Fastest route from A to E: ";
        graph.printRoute(route);

        // Validate the route with given constraints:
        // Assume the vehicle starts at time 8 (e.g., 8 AM) and has a capacity of 15.
        int startTime = 8;
        int vehicleCapacity = 15;
        if (graph.validateRoute(route, startTime, vehicleCapacity)) {
            cout << "The route satisfies the time window and capacity constraints." << endl;
        } else {
            cout << "The route does not satisfy the time window or capacity constraints." << endl;
        }
    } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
