/* Write a program to detect a cycle in a directed graph using DFS */

#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    bool dfs(int node, vector<int>& visited, vector<int>& pathVisited) {
        visited[node] = 1;
        pathVisited[node] = 1;

        for(auto neighbour : adj[node]) {
            if (!visited[neighbour]) {
                if (dfs(neighbour, visited, pathVisited)) 
                    return true;
            } else if (pathVisited[neighbour]) {
                // If the neighbor is visited and also in the current path -> cycle
                return true;
            }
        }
    }

    bool isCyclic() {
        vector<int> visited(V, 0);
        vector<int> pathVisited(V, 0);

        // consider that the graph has connected components
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, visited, pathVisited))
                    return true;
            }
        }
        return false;
    }
};

// ----------- Driver Code -----------
int main() {
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 1); // Cycle here
    g.addEdge(4, 5);

    if (g.isCyclic()) {
        cout << "Cycle detected in the graph\n";
    } else {
        cout << "No cycle detected\n";
    }

    return 0;
}
