#include <vector>
#include <queue>
#include <iostream>
using namespace std;

bool isBipartiteBFS(int& V, vector<vector<int>>& adj) {
    vector<int> colored(V, -1); // initially all nodes are non-colored (-1)
    queue<int> q;
    colored[0] = 0; // start with color 0
    q.push(0);

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbour : adj[node]) {
            if (colored[neighbour] == -1) {
                // not coloured node
                colored[neighbour] = !colored[node];
            } else {
                // neighbour is colored
                // check the colour
                if (colored[neighbour] == colored[node]) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    int V = 4;
    vector<vector<int>> adj(V);

    // Create a bipartite graph
    adj[0] = {1, 3};
    adj[1] = {0, 2};
    adj[2] = {1, 3};
    adj[3] = {0, 2};

    cout << "Using BFS: ";
    if (isBipartiteBFS(V, adj)) cout << "Graph is Bipartite" << endl;
    else cout << "Graph is NOT Bipartite" << endl;

    return 0;
}
