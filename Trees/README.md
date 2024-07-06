### Terminology of Trees:

- Root, Nodes and Edges 
- Nodes can be terminal/non-terminal, internal/external OR leaf/non-leaf nodes
- Subtree: Collection of nodes below a root node
- Parent and Child
- Siblings : Children of same parent node (at the same level)
- Descendants : Set of all nodes that can be reached from a parent node (downward)
- Ancestors: Set of all nodes that can be reached from a node at a lower level (upward)
- Degree of a node: No. of direct children nodes that the particular node has
                    Degree of a tree cannot be calculated
- Level - For a tree, it starts at 1 (at the root level) - counted by no. of nodes
- Height of a tree - starts at 0 (count edges)
- Forest : Collection of trees - no particular node - a forest can be converted to a tree by adding a root node 

### Binary Tree: 

- every node has max of 2 child nodes 
- can have less than 2 children
- left and right children
- left skewed tree: every node only has 1 left node, no right nodes at all 
- right skewed tree: every node only has 1 right node, no left nodes at all

### Unlabelled Nodes:
- Number of Binary Trees with given N number of nodes = (2*n) Cn / (n+1) - This is called Catalan number
- The number of trees here with max height = 2^(n-1)


### Labelled Nodes:
- Every possible shape can be filled with N labels in N factorial ways