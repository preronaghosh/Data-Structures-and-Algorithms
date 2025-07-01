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


*** DFS Based Approach:
- Start from node 0 and recurse all neighbours 
- After exploring all nodes, put the current node to a stack
- Then go to the next unvisited node in the graph and repeat steps 1 and 2
- At the end, keep popping from stack one by one until it is empty
- The result is one of the linear orderings of Topo sort


*** Intuition behind this algorithm:
- For a node, once all of its neighbours have been explored, we know it has been completely explored.
- That is when we put the node into a stack because every other node that came after it is already in the stack. 


*** Points to remember:
- If you cannot generate a full topological sort, the graph has a cycle.
- So, topological sort is also a tool for detecting cycles in a directed graph.
*/


#include <vector>
#include <stack>
using namespace std;

// DFS Based approach code
void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, stack<int>& st) {
    visited[node] = true;

    for(int neighbour : graph[node]) {
        if (!visited[node]) {
            dfs(neighbour, graph, visited, st);
        }
    }
    // add the current node to the stack after visiting all neighbours
    st.push(node);
}

// Topo sort driver
vector<int> topoSortDFS(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    stack<int> st;

    for (int i=0; i<V; i++) {
        if (!visited[i])
            dfs(i, adj, visited, st);
    }

    // get the linear ordering
    vector<int> res;
    while (!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }
    return res;
}