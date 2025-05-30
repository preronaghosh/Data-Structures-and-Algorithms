/* Depth First Search - Visit a node, take one sub-node, push current node to stack (done by recursion automatically), visit the new node */

#include <vector>
#include <iostream>
using namespace std;

void dfs(int node, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for(int neighbour : adj[node]) {
        if (!visited[neighbour]) {
            dfs(neighbour, adj, visited);
        }
    }
}

int main() {
    int n = 6; // number of nodes (numbered from 0 to 5)
    vector<vector<int>> adj(n);

    // Edges (undirected)
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[0].push_back(2);
    adj[2].push_back(0);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[2].push_back(4);
    adj[4].push_back(2);

    adj[3].push_back(5);
    adj[5].push_back(3);

    vector<bool> visited(n, false);

    cout << "DFS traversal starting from node 0:\n";
    dfs(0, adj, visited);

    return 0;
}