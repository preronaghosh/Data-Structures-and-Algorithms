/* 

1. Pre-requisites:
- Graph must be directed acyclic graph (not undirected, and has no cycles)

2. Applications:
- Course scheduling
- Build systems (compile order of dependencies)
- Task scheduling
- Deadlock detection
- Dependency resolution (e.g., package managers)

3. Two main ways of doing Topo Sort:
- DFS based approach
- BFS / Kahn's algorithm approach


*** BFS Based Approach/Kahn's Algorithm:
- Generate an indegree array for n number of nodes in the graph
- First, insert all nodes with indegree 0 into the queue
- Pop one node from queue and explore its neighbours
- if neighbour is unvisited, reduce its indegree by one



4. Important Terms for this algo:
- Indegree = number of incoming edges into a node

*/

#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> topoSort_KahnAlgo_BFS(int V, vector<vector<int>>& adj) {
    // create an indegree array for all the nodes
    vector<int> indegree(V, 0);
    for (auto& node : adj) {
        for(int& neighbour : node) indegree[neighbour]++;
    }

    // create a queue for BFS algorithm
    queue<int> q;

    /* if there are any nodes with indegree as 0 in the graph, 
    push them to the queue and start BFS from one of them */
    for(int i=0; i<V; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    // resultant vector with one of the linear orderings
    vector<int> topoOrder;

    // start running BFS
    while (!q.empty()) {
        int node = q.front(); q.pop();

        for (auto& neighbour : adj[node]) {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
        
        // all edges going out from this node has been explored, so push it into the linear ordering now
        topoOrder.push_back(node);
    }

    return topoOrder;
}

int main() {
    // Example graph:
    // 0 → 2, 3
    // 1 → 3, 4
    // 2 → (no edges)
    // 3 → 5
    // 4 → 5
    // 5 → (no edges)

    int V = 6;
    vector<vector<int>> adj(V);

    adj[0] = {2, 3};
    adj[1] = {3, 4};
    adj[2] = {};
    adj[3] = {5};
    adj[4] = {5};
    adj[5] = {};

    vector<int> result = topoSort_KahnAlgo_BFS(V, adj);

    cout << "Topological Sort Order:" << endl;
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}