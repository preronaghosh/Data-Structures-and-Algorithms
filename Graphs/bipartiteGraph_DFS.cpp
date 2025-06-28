#include <vector>
#include <queue>
#include <iostream>
using namespace std;

// colors one component
bool dfsTraversal(int node, int& V, vector<vector<int>>& adj, vector<int>& colored, int color) {
    colored[node] = color; // start coloring with 0

    for(auto neighbour : adj[node]) {
        if (colored[neighbour] == -1) {
            if (!dfsTraversal(neighbour, V, adj, colored, 1 - color)) return false;
        } else {
            // check if it has the same colour as the parent node
            if (colored[neighbour] == colored[node]) return false;
        }
    }
    return true;
}

// graph may or may not have connected components 
bool checkGraphBipartite(int &V, vector<vector<int>>& adj) {
    vector<int> colored(V, -1); // initially all nodes are non-colored (-1)

    for(int start=0; start<V; start++) {
        if (colored[start] == -1) {
            if (!dfsTraversal(start, V, adj, colored, 0)) {
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

    cout << "Using DFS: ";
    if (checkGraphBipartite(V, adj)) cout << "Graph is Bipartite" << endl;
    else cout << "Graph is NOT Bipartite" << endl;


    V = 3;
    vector<vector<int>> adj2(V);

    // Create a non-bipartite graph (odd cycle)
    adj2[0] = {1, 2};
    adj2[1] = {0, 2};
    adj2[2] = {0, 1};

    cout << "Using DFS: ";
    if (checkGraphBipartite(V, adj2)) cout << "Graph is Bipartite" << endl;
    else cout << "Graph is NOT Bipartite" << endl;

    return 0;
}
