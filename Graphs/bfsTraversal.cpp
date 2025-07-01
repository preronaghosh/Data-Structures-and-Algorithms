#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, const vector<vector<int>>& adjList, vector<bool>& visited) {
    queue<int> q;
    visited[start] = true;
    q.push(start); 

    while (!q.empty()) {
        int temp = q.front();
        q.pop();

        for(int neighbour : adjList[temp]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                q.push(neighbour);
            }
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

    cout << "BFS traversal starting from node 0:\n";
    bfs(0, adj, visited);

    return 0;
}