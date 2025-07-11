/* Implement Kruskal's Algorithm 

** Algorithm:
1. Take a list of all edges with their weight inn the format : {weight, sourceNode, destinationNode}
2. Sort it in the increasing order of weights
3. Take an element from the array of {weight, u, v}:
    - for every element, check if u is connected to v or not using DSU 
    - If not connected, take this edge
    - If they are connected, it means they are part of the same graph -> which means there is a path between them already
    - So, don't connected nodes.
4. Keep traversing the list till the end. We will have an MST finally.

*/


#include <vector>
#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;

vector<int>& parent;

int findParent(int node) {
    if (parent[node] != node) {
        parent[node] = findParent(parent[node]);
    }
    return parent[node];
}

// Union two nodes if they are not connected
void unionNodes(int u, int v) {
    int pu = findParent(u);
    int pv = findParent(v);
    if (pu != pv) {
        parent[pu] = pv; // attach one root to another
    }
}

pair<int, vector<pair<int,int>>> spanningTree(int V, vector<vector<pair<int,int>>>& adj) {
    // form the sorted edge list with weights from adj
    vector<tuple<int,int,int>> edges;
    for(int u=0; u<V; u++) {
        for (auto& [v, wt] : adj[u]) {
            edges.push_back({wt, u, v});
        }
    }

    // sort the edges[] in increasing order of weights
    sort(edges.begin(), edges.end());

    vector<pair<int,int>> mst; // to hold all edges taken in mst
    int sum = 0; // store the total sum of path weights in the mst formed

    // apply kruskal's algorithm to edges[]
    for (auto& edge : edges) {
        int wt = std::get<0>(edge);
        int u = std::get<1>(edge);
        int v = std::get<2>(edge);

        if (findParent(u) == findParent(v)) {
            // nodes are already connected, so a path exists
            // don't consider this edge
            continue; 
        }

        // nodes are not connected and also has minimum weight
        mst.push_back({u,v});
        sum += wt;

        // connect the two nodes
        unionNodes(u, v);

    }

    // return the mst weight
    return {sum, mst};
}

int main() {
    int V = 6; // number of vertices (0-based indexing)

    // Initialize DSU parent array
    parent.resize(V);
    for (int i = 0; i < V; ++i)
        parent[i] = i;

    // Create adjacency list {node, weight}
    vector<vector<pair<int, int>>> adj(V);
    
    // Sample undirected graph
    adj[0].push_back({1, 4});
    adj[1].push_back({0, 4});

    adj[0].push_back({2, 4});
    adj[2].push_back({0, 4});

    adj[1].push_back({2, 2});
    adj[2].push_back({1, 2});

    adj[1].push_back({3, 5});
    adj[3].push_back({1, 5});

    adj[2].push_back({3, 5});
    adj[3].push_back({2, 5});

    adj[3].push_back({4, 3});
    adj[4].push_back({3, 3});

    adj[4].push_back({5, 1});
    adj[5].push_back({4, 1});

    adj[3].push_back({5, 2});
    adj[5].push_back({3, 2});

    // Run Kruskal's Algorithm
    auto [totalWeight, mstEdges] = spanningTree(V, adj);

    // Output MST result
    cout << "Total weight of MST: " << totalWeight << "\n";
    cout << "Edges in MST:\n";
    for (auto& [u, v] : mstEdges) {
        cout << u << " - " << v << "\n";
    }

    return 0;
}