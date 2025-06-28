#include <vector>
#include <queue>
#include <iostream>
using namespace std;

// colors one component
bool bfsTraversal(int start, int& V, vector<vector<int>>& adj, vector<int>& colored) {
    queue<int> q;
    colored[start] = 0; // start with color 0
    q.push(start);

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbour : adj[node]) {
            if (colored[neighbour] == -1) {
                // not coloured node
                colored[neighbour] = 1 - colored[node];
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

// graph may or may not have connected components 
bool checkGraphBipartite(int &V, vector<vector<int>>& adj) {
    vector<int> colored(V, -1); // initially all nodes are non-colored (-1)

    for(int start=0; start<V; start++) {
        if (colored[start] == -1) {
            if (!bfsTraversal(start, V, adj, colored)) {
                return false;
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
    if (checkGraphBipartite(V, adj)) cout << "Graph is Bipartite" << endl;
    else cout << "Graph is NOT Bipartite" << endl;

    return 0;
}
