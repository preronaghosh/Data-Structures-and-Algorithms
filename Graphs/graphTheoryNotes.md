
# 📘 Graph Theory Notes

## 🔁 Ways to Traverse a Graph

### ✅ Breadth-First Search (BFS)
- Explores level by level (uses a **queue**).
- Used in:
  - Shortest path (unweighted)
  - Cycle detection
  - Bipartite check
  - Level order traversal


### ✅ Depth-First Search (DFS)
- Explores as deep as possible (uses **recursion or stack**).
- Used in:
  - Cycle detection
  - Topological sort
  - Connected components
  - Pathfinding


## 🔁 Cycle Detection

### 🔄 In Undirected Graphs

#### 1. BFS Approach
- Track parent with each node in the queue.
- If you visit a neighbor that's already visited **and it's not the parent**, there's a cycle.

#### 2. DFS Approach
- For each neighbor:
  - If not visited, recursively DFS with current as parent.
  - If visited and not parent → **cycle detected**.


### 🔄 In Directed Graphs

#### 1. Visited[] + DFS + Path Visited[]
- Maintain a path visited array to track nodes in the current path.
- If a node is visited and already in the recursion stack → **cycle exists**.
- After exploring a new node, while backtracking, remove the current node that was added to the path.


#### 2. Kahn’s Algorithm (BFS Approach)
- Count the number of incoming edges for all nodes, also called indegree of all nodes.
- Push all nodes that have 0 indegree into the queue and then start BFS
- For every adjacent node of current node under processing, reduce the indegree by 1.
- If indegree of the adjacent node becomes 0, then push it to the queue as well.

- At the end, if we can’t process all nodes (queue becomes empty early) and the topo sort order could not be generated (number of nodes in order is less than the number of vertices), there's a cycle.


## 🟥 Bipartite Graph Check

### Using BFS or DFS:
- Color graph with 2 colors such that two adjacent nodes don't have the same color.
- If two adjacent nodes have the same color -> not bipartite.

Algorithm:
- Instead of visited[], use a color[] which is initially -1 (uncolored). Then either color it with 0 or 1.
- Use either BFS or DFS but if we find an adjacent node that has already been colored, check the color.
- Return `false` if it is the same color as parent node.

Application:
- Useful when trying to determine if a set of items can be grouped into two different groups or not.


## 🧮 Topological Sort

### ➕ Using DFS
- Usual DFS traversal has to be done.
- While returning, push the current node into the stack.
- This stores a valid linear ordering in the stack in reverse order.

### ➕ Using Kahn’s Algorithm (BFS)
- Maintain indegree array.
- Queue nodes with 0 indegree.
- Remove nodes and decrease indegrees of neighbors.
- If all nodes are visited → topological sort is valid.


## 📏 Shortest Path

### 🟩 Unweighted Graphs
- Use **BFS** (each edge is weight 1).

### 🟨 Weighted Graphs

#### ✅ Dijkstra's Algorithm
- For non-negative weights.
- Use min-heap (priority queue).

#### ✅ Bellman-Ford Algorithm
- For negative weights.
- Relax all edges `V-1` times.
- Detect negative cycle.

#### ✅ Topological Sort (for DAGs)
- Works on Directed Acyclic Graphs.
- Relax edges in topological order.


## ⚖️ Disjoint Set Union (DSU) / Union Find

### 🛠 Operations
- **Find**: get parent.
- **Union**: merge sets.
- Used in:
  - Kruskal’s MST
  - Cycle detection
  - Connected components


## 🌉 Minimum Spanning Tree (MST)

### ✅ Kruskal's Algorithm
- Sort all edges by weight.
- Add edge if it doesn't form a cycle using DSU.

### ✅ Prim's Algorithm
- Use priority queue to always pick minimum weight edge to expand.


## 📌 Summary Table

| Concept          | Traversal | Directed | Undirected | Weighted | Unweighted |
|------------------|-----------|----------|------------|----------|------------|
| BFS              | ✅        | ✅       | ✅         | ❌       | ✅         |
| DFS              | ✅        | ✅       | ✅         | ❌       | ✅         |
| Topo Sort        | ✅        | ✅       | ❌         | ✅ (DAG) | ✅ (DAG)   |
| Dijkstra         | ✅        | ✅       | ✅         | ✅       | ❌         |
| Bellman-Ford     | ✅        | ✅       | ✅         | ✅       | ❌         |
| DSU (Union-Find) | ❌        | ❌       | ✅         | ✅       | ✅         |


