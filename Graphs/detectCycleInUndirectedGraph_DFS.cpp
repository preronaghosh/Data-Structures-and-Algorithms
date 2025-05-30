
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited, bool& foundCycle) {
    visited[node] = true;

    if (foundCycle) return; // propagate result faster

    for (auto& neighbour: adj[node]) {
        if (!visited[neighbour]) {
            dfs(neighbour, node, adj, visited, foundCycle);
        } else {
            if (neighbour != parent) {
                foundCycle = true;
                return;
            }
        }
    }
}

bool hasCycle(int& V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    bool foundCycle = false;
    for(int i=0; i<V; i++) {
        if (!visited[i]) {
            dfs(i, -1, adj, visited, foundCycle);
            if (foundCycle) return true;
        }
    }
    return false;
}

int main() {
    int V = 7; // number of vertices
    vector<vector<int>> adj(V);
    
    // Add undirected edges
    adj[0].push_back(1);
    adj[0].push_back(2);
    
    adj[1].push_back(0);
    adj[1].push_back(4);
    
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[2].push_back(5);
    
    adj[3].push_back(2);
    
    adj[4].push_back(1);
    adj[4].push_back(6);

    adj[5].push_back(2);
    adj[5].push_back(6);

    adj[6].push_back(4);
    adj[6].push_back(5);

    bool res = hasCycle(V, adj);
    cout << "1st Graph: " << (res ? "Has cycle" : "No cycle") << endl;

    // -------------------------------------------------
    // Test Graph with no cycle
    int n = 3;
    vector<vector<int>> adj_noCycle(n);

    adj_noCycle[0].push_back(1);

    adj_noCycle[1].push_back(0);
    adj_noCycle[1].push_back(2);

    adj_noCycle[2].push_back(1);

    res = hasCycle(n, adj_noCycle);
    cout << "2nd graph: " << (res ? "Has cycle" : "No cycle") << endl;
    
    return 0;
}