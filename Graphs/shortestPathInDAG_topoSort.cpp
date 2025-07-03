#include <vector>
#include <iostream>
#include <stack>
using namespace std;

// dfs approach
void topoSort(int node, vector<bool>& visited, stack<int>& st, vector<vector<pair<int,int>>>& adj) {
    visited[node] = true;

    for(auto& neighbour : adj[node]) {
        if (!visited[neighbour.first]) {
            topoSort(neighbour.first, visited, st, adj);
        }
    }

    st.push(node);
}

vector<int> shortestPathInDAG(int N, int src, vector<vector<pair<int,int>>> adj) {
    stack<int> st;
    vector<bool> visited(N, false);

    // generate stack with linear ordering using topo sort
    for (int i=0; i<N; i++) {
        if (!visited[i]) {
            topoSort(i, visited, st, adj);
        }
    }

    // we have the stack now
    vector<int> dist(N, INT_MAX);
    dist[src] = 0;

    while (!st.empty()) {
        int u = st.top(); st.pop();

        if (dist[u] != INT_MAX) { // compute the dist to v only if u has already been computed
            for(auto& nbr : adj[u]) {
                int v = nbr.first;
                int wt = nbr.second;

                // update distance[] with min distances
                if (dist[v] > dist[u] + wt) {
                    dist[v] = dist[u] + wt;
                }
            }
        }       
    }
    return dist;
}

int main() {
    int N = 6;  // number of nodes
    vector<vector<pair<int,int>>> adj(N); // adjacency list

    // Example DAG:
    // 0 -> 1 (weight 2)
    // 0 -> 4 (weight 1)
    // 1 -> 2 (weight 3)
    // 4 -> 2 (weight 2)
    // 2 -> 3 (weight 6)
    // 4 -> 5 (weight 4)
    // 5 -> 3 (weight 1)

    adj[0].push_back({1, 2});
    adj[0].push_back({4, 1});
    adj[1].push_back({2, 3});
    adj[4].push_back({2, 2});
    adj[2].push_back({3, 6});
    adj[4].push_back({5, 4});
    adj[5].push_back({3, 1});

    int src = 0;
    vector<int> dist = shortestPathInDAG(N, src, adj);

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < N; ++i) {
        if (dist[i] == INT_MAX)
            cout << "Node " << i << ": Unreachable\n";
        else
            cout << "Node " << i << ": " << dist[i] << "\n";
    }

    return 0;
}