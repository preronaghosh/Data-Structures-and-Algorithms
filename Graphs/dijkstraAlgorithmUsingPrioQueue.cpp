/* Implement Dijkstra's algorithm using a Priority Queue + BFS approach

Notes:
- Not applicable for graphs with negative weights.  
- Does not work with cycles in a graph with negative weight
    - Explanation in video: https://www.youtube.com/watch?v=V6H1qAeB-l4&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=32
    - The algorithms keeps running infinitely with negative weights because the newDist keeps reducing negatively and 
      is always better than the previous less negative weight
*/

#include <vector>
#include <queue>
using namespace std;

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

