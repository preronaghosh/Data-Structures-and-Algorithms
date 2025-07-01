/* Detect a cycle in an Undirected Graph - using BFS */

#include <vector>
#include <iostream>
#include <queue>
using namespace std;

// Using breadth first search
/* Algorithm :
- use a queue to store every node after visiting it 
- track neighbour nodes and visit them. Note down the parent node of each node that we are visiting
- To keep track of which direction we are coming from
- if we meet at the same node even though the parent nodes are different, then there is a cycle
*/

bool detectCycle(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[start] = true;
    queue<pair<int, int>> q;
    q.push({start, -1}); // queue stores both current node and its parent node

    while (!q.empty()) {
       int currNode = q.front().first; 
       int parentNode = q.front().second;
       q.pop();

       for (auto& neighbour : adj[currNode]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                q.push({neighbour, currNode});
            } else if (neighbour != parentNode) {
                // if the neighbour node is in the current and being revisited again
                // that means there is a cycle
                return true;
            }
       }
    }
    return false;  
}

bool isCycle(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    for (int i=0; i<V; i++) {
        if (!visited[i]) {
            if (detectCycle(i, adj, visited)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int V = 7; // number of vertices
    vector<vector<int>> adj(V);
    
    // Add undirected edges
    adj[0].push_back(1);
    adj[0].push_back(2);
    
    adj[1].push_back(0);
    adj[1].push_back(4);
    
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[2].push_back(5);
    
    adj[3].push_back(2);
    
    adj[4].push_back(1);
    adj[4].push_back(6);

    adj[5].push_back(2);
    adj[5].push_back(6);

    adj[6].push_back(4);
    adj[6].push_back(5);

    bool res = isCycle(V, adj);
    std::cout << (res ? "Has cycle" : "No cycle") << std::endl;
    
    return 0;
}
