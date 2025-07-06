#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool bellmanFord(int V, int E, vector<Edge>& edges, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Step 1: Relax all edges V - 1 times
    for (int i = 0; i < V - 1; ++i) {
        for (const auto& edge : edges) {
            if (dist[edge.u] != INT_MAX && dist[edge.u] + edge.weight < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.weight;
            }
        }
    }

    // Step 2: Check for negative weight cycles
    for (const auto& edge : edges) {
        if (dist[edge.u] != INT_MAX && dist[edge.u] + edge.weight < dist[edge.v]) {
            cout << "Graph contains a negative weight cycle.\n";
            return false;
        }
    }

    // Print distances
    cout << "Vertex distances from source " << src << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << i << " -> " << (dist[i] == INT_MAX ? "INF" : to_string(dist[i])) << "\n";
    }

    return true;
}
