/* Detect a cycle in a DAG using Topological Sort

Step-by-step (Kahn’s Algorithm):
- Compute in-degrees of all nodes.
- Add nodes with in-degree 0 to a queue.

Process the queue:
- Remove a node.
- Decrease in-degrees of its neighbors.
- If any neighbor’s in-degree becomes 0, enqueue it.
- Count the number of nodes processed.
- If the count < total number of nodes → the graph has a cycle.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool hasCycle_KahnTopoSort(int V, vector<vector<int>>& adj) {
    vector<int> indegree(V, 0);

    // Step 1: Compute in-degrees
    for (int u = 0; u < V; ++u) {
        for (int v : adj[u]) {
            indegree[v]++;
        }
    }

    // Step 2: Enqueue nodes with in-degree 0
    queue<int> q;
    for (int i = 0; i < V; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    int count = 0; // counts processed nodes

    // Step 3: Kahn’s BFS
    while (!q.empty()) {
        int node = q.front(); q.pop();
        count++;

        for (int neighbor : adj[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // Step 4: If not all nodes processed → cycle exists
    return count != V;
}

int main() {
    // Example with a cycle:
    // 0 → 1 → 2 → 3 → 1 (cycle: 1 → 2 → 3 → 1)
    int V = 4;
    vector<vector<int>> adj(V);
    adj[0] = {1};
    adj[1] = {2};
    adj[2] = {3};
    adj[3] = {1}; // creates cycle

    if (hasCycle_KahnTopoSort(V, adj)) {
        cout << "Cycle detected in the graph (Kahn’s Algorithm)." << endl;
    } else {
        cout << "No cycle. The graph is a DAG." << endl;
    }

    return 0;
}
