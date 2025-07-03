/* 
** Problem Statement:
Given an undirected graph with unit weights (i.e., every edge has weight = 1), 
find the shortest distance from a given source node to all other nodes. 

** Algorithm:
- Create an adjacency list adj of size V (number of vertices).
- Initialize a distance array dist of size V with INT_MAX.
- Set dist[src] = 0.
- Initialize a queue and push the src node into it.
- While the queue is not empty:
    - Pop a node u from the queue.
    - For each neighbor v of u:
    - If dist[v] > dist[u] + 1:
    - Update dist[v] = dist[u] + 1
    - Push v into the queue.

- Return the dist array.

---------------------------------------------------------------------------------------------------

** Notes:
- BFS is the most optimal algorithm for undirected graphs with unit weights
- we can also remove storing the distance in the queue with the node, and instead
  get it from the distance array itself
  
*/

#include <vector>
#include <queue>
using namespace std;

vector<int> getShortestPath(vector<vector<int>>& adj, int src, int V) {
    // declare the distance vector that will be returned
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    
    // use BFS algorithm
    queue<pair<int,int>> q; // will store {node, distance from src to node}
    
    q.push({src, 0});

    while (!q.empty()) {
        int node = q.front().first;
        int d = q.front().second;
        q.pop();

        for(int& neighbour : adj[node]) {
            if (dist[neighbour] > d+1) {
                dist[neighbour] = d+1;
                q.push({neighbour, d+1});
            }
        }
    }

    return dist;
}

// Without storing distance with node in queue
vector<int> getShortestPath(vector<vector<int>>& adj, int src, int V) {
    // declare the distance vector that will be returned
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    
    // use BFS algorithm
    queue<int> q; // will store {node}, get distance from distance array
    
    q.push(src);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for(int& neighbour : adj[node]) {
            if (dist[neighbour] > dist[node] + 1) {
                dist[neighbour] = dist[node] + 1;
                q.push(neighbour);
            }
        }
    }

    return dist;
}