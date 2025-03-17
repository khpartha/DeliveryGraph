#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <limits>
#include <stdexcept>
#include <string>
#include <algorithm>

using namespace std;

// Structure to represent a delivery location (vertex)
// with a delivery time window and demand (load)
struct DeliveryLocation {
    string id;
    int timeWindowStart; // Earliest time the delivery can be made (e.g., in hours)
    int timeWindowEnd;   // Latest time the delivery can be made
    int demand;          // Load at this delivery point (e.g., number of packages)
};

// Structure to represent an edge from one location to another with a travel cost
struct Edge {
    string destination;
    double weight; // Travel time or distance between locations
};

class DeliveryGraph {
public:
    // Add a delivery location (vertex) to the graph.
    void addLocation(const DeliveryLocation &loc) {
        if (locations.count(loc.id)) {
            throw runtime_error("Location '" + loc.id + "' already exists.");
        }
        locations[loc.id] = loc;
        adjList[loc.id] = vector<Edge>(); // Initialize an empty adjacency list
    }

    // Add an edge (bidirectional) between two locations with the given travel weight.
    void addEdge(const string &src, const string &dest, double weight) {
        if (locations.find(src) == locations.end() || locations.find(dest) == locations.end()) {
            throw runtime_error("One or both locations not found.");
        }
        adjList[src].push_back({dest, weight});
        // Assuming the roads are bidirectional:
        adjList[dest].push_back({src, weight});
    }

    // Use Dijkstra's algorithm to compute the fastest route (lowest travel time)
    // from source to destination.
    vector<string> shortestPath(const string &source, const string &destination) {
        unordered_map<string, double> dist;
        unordered_map<string, string> prev;
        for (const auto &pair : locations) {
            dist[pair.first] = numeric_limits<double>::infinity();
        }
        dist[source] = 0.0;

        // Priority queue: (current travel time, location id)
        using pii = pair<double, string>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0.0, source});

        while (!pq.empty()) {
            auto [currTime, u] = pq.top();
            pq.pop();
            if (currTime > dist[u])
                continue;
            if (u == destination)
                break;
            for (const auto &edge : adjList[u]) {
                double alt = dist[u] + edge.weight;
                if (alt < dist[edge.destination]) {
                    dist[edge.destination] = alt;
                    prev[edge.destination] = u;
                    pq.push({alt, edge.destination});
                }
            }
        }

        // Reconstruct the path from source to destination.
        vector<string> path;
        if (dist[destination] == numeric_limits<double>::infinity()) {
            throw runtime_error("No path found from " + source + " to " + destination);
        }
        for (string at = destination; at != source; at = prev[at]) {
            path.push_back(at);
        }
        path.push_back(source);
        reverse(path.begin(), path.end());
        return path;
    }

    // Validate a given route with respect to time windows and vehicle capacity.
    // The route is validated based on:
    // 1. The arrival time at each location must fall within its time window.
    // 2. The cumulative demand does not exceed the vehicle's capacity.
    // For simplicity, if you arrive earlier than the start of the time window,
    // you wait until the window opens.
    bool validateRoute(const vector<string> &route, int startTime, int vehicleCapacity) {
        int currentTime = startTime;
        int totalDemand = 0;

        for (size_t i = 0; i < route.size(); i++) {
            const auto &loc = locations.at(route[i]);
            // Wait until the time window opens if you arrive too early.
            if (currentTime < loc.timeWindowStart) {
                currentTime = loc.timeWindowStart;
            }
            // If arrival time exceeds the time window, route is invalid.
            if (currentTime > loc.timeWindowEnd) {
                return false;
            }
            totalDemand += loc.demand;
            if (totalDemand > vehicleCapacity) {
                return false;
            }
            // Add travel time to reach the next location, if any.
            if (i < route.size() - 1) {
                bool foundEdge = false;
                for (const auto &edge : adjList[route[i]]) {
                    if (edge.destination == route[i + 1]) {
                        currentTime += static_cast<int>(edge.weight);
                        foundEdge = true;
                        break;
                    }
                }
                if (!foundEdge) {
                    return false;
                }
            }
        }
        return true;
    }

    // Utility to print a route
    void printRoute(const vector<string> &route) {
        for (size_t i = 0; i < route.size(); i++) {
            cout << route[i];
            if (i != route.size() - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
    }

private:
    unordered_map<string, DeliveryLocation> locations;
    unordered_map<string, vector<Edge>> adjList;
};
