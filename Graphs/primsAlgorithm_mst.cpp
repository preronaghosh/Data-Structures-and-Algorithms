/* Write the Prim's algorithm to find the minimum spanning tree from a graph */

#include <vector>
#include <queue>
#include <iostream>
#include <tuple>
using namespace std;

int getMstSum(int V, vector<vector<pair<int,int>>>& adj) {
    // minheap of {weight, node, parentNode}
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;

    vector<pair<int,int>> mstEdges;
    int sum = 0; // total weight of mst

    vector<int> visited(V, 0); // initially every node is unvisited

    // push starting node to priority queue
    pq.push({0,0,-1});

    while (!pq.empty()) {
        auto [wt, node, parent] = pq.top();
        pq.pop();

        // if node is unvisited
        if (visited[node] == 0) {
            visited[node] = 1; 
            // push edge to mst[]
            if (parent != -1) mstEdges.push_back({parent, node});
            sum += wt;

            // check all unvisited adjacent nodes and push to minheap if unvisited
            for(auto& [adjNode, pathWt] : adj[node]) {
                if (visited[adjNode] == 0) {
                    pq.push({pathWt, adjNode, node});
                }
            } 
        }
    }
    return sum;
}

int main() {
    int V = 5; // Number of vertices
    vector<vector<pair<int, int>>> adj(V);

    // Sample undirected weighted graph
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({3, 3});
    adj[3].push_back({0, 3});

    adj[1].push_back({2, 1});
    adj[2].push_back({1, 1});

    adj[1].push_back({3, 3});
    adj[3].push_back({1, 3});

    adj[2].push_back({4, 4});
    adj[4].push_back({2, 4});

    adj[3].push_back({4, 5});
    adj[4].push_back({3, 5});

    int totalWeight = getMstSum(V, adj);
    cout << "Total weight of MST: " << totalWeight << endl;

    return 0;
}