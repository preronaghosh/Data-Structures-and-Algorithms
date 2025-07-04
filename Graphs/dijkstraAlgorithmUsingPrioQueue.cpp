/* Implement Dijkstra's algorithm using a Priority Queue + BFS approach

Notes:
- Not applicable for graphs with negative weights.  
- Does not work with cycles in a graph with negative weight
    - Explanation in video: https://www.youtube.com/watch?v=V6H1qAeB-l4&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=32
    - The algorithms keeps running infinitely with negative weights because the newDist keeps reducing negatively and 
      is always better than the previous less negative weight


- Time Complexity: E log V, where E = number of edeges, V = number of nodes

*/

#include <vector>
#include <queue>
#include <iostream>
#include <climits>
using namespace std;

// return a distance array with shortest paths from src to every other node
vector<int> getShortestPath(int src, int V, vector<vector<vector<int>>>& adj) {
    // create a min heap to store: {distance, node}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    
    // create a distance array and initialize all nodes as unreachable (INT_MAX)
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // add the src node to prioQueue and start BFS traversal
    pq.push({dist[src], src});

    while (!pq.empty()) {
        // pop off the minimum value from minHeap with least distance
        int node = pq.top().second;
        int distance = pq.top().first;
        pq.pop();

        for (auto& neighbour : adj[node]) {
            int nextNode = neighbour[0];
            int weight = neighbour[1];

            int newDist = distance + weight;

            if (newDist > dist[nextNode]) {
                dist[nextNode] = newDist;
                pq.push({newDist, nextNode});
            }
        }
    }

    return dist;
}

/* Return array of nodes in order which generate the shortest path between src and dest nodes.
   Else, return {-1} when there is not shortest path from src to dest node.

   This solution is good for small graphs; can be optimized for larger graphs and less memory usage 
*/

vector<int> printShortestPath(int src, int dest, int V, vector<vector<vector<int>>>& adj) {
    // pair of {totalDistance from src to this node, full path from src upto this node}
    priority_queue<pair<int,vector<int>>, vector<pair<int,vector<int>>>, greater<>> pq;

    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    pq.push({0, {src}});

    while (!pq.empty()) {
        int d = pq.top().first;
        vector<int> fullPath = pq.top().second;
        int currNode = fullPath.back();
        pq.pop();

        if (currNode == dest) {
            return fullPath;
        }

        for (auto& neighbor : adj[currNode]) {
            int nextNode = neighbor[0]; 
            int wt = neighbor[1];

            int newDist = d + wt;
            if (newDist < dist[nextNode]) {
                dist[nextNode] = newDist;
                vector<int> newPath = fullPath;
                newPath.push_back(nextNode);
                pq.push({newDist, newPath});
            }
        }
    }
    return {-1};
}

/* More optimized solution to return the shortest path as an array of all included nodes 

- Use DFS

*/
vector<int> getShortestPathDijkstras(int src, int dest, int V, vector<vector<vector<int>>>& adj) {

}

int main() {
    int V = 5;
    vector<vector<vector<int>>> adj(V);
    adj[0] = {{1, 2}, {2, 4}};
    adj[1] = {{2, 1}, {3, 7}};
    adj[2] = {{4, 3}};
    adj[3] = {{4, 1}};
    adj[4] = {};

    vector<int> path = printShortestPath(0, 4, V, adj); // Expected path: 0 → 1 → 2 → 4 (total weight = 6)
    for (int& val : path) cout << val << " -> ";
    cout << endl;
}