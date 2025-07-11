#### Notes:

A Minimum Cost Spanning Tree (MST) is a subset of the edges of a connected, undirected, weighted graph that satisfies the following conditions:
- Spanning: Contains all the vertices from original graph
- Edges: number of edges is (V-1) (no of vertices - 1)
- Tree: has no cycles and all vertices should be connected
- Minimum: Sum of weights of its edges is as small as possible

IMPORTANT: 
- Every node is reachable from every other node

Use of MST:
- Linking different nodes
- Network design (e.g., laying cables or roads)
- Clustering in machine learning
- Circuit design

Solution Algos: 
- Prim's Algorithm 
- Kruskal Algorithms

#### Prim's Algorithm:
- Take a Greedy appraoch
- First consider edges that have the least weight 
- If the edge has not already been taken, consider it
- Eventually, if there is already a path leading to a node, then don't take
- Check `primsAlgorith_mst.cpp` for algorithm and code explanation


#### Kruskal's Algorithm:
- Also a Greedy approach
- Create a list of all given edges and weights in the format : {weight, src, dest} 
- Sort it in increasing order of weights (greedy part) 
- Iterate over the list:
  - For every combination, if node u and node v are not part of the same graph already, add the edge to mst
  - If they are already connected, there is already a path between them. So, do not add this edge.
  - Go to the next edge 
