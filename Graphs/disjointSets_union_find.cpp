/* 
Disjoint Set - Union-Find Algorithm
*/

#include <vector>
#include <iostream>
using namespace std;

class UnionFindAlgo {
    vector<int> parent;
    vector<int> rank; // for union by rank
    vector<int> size; // for union by size (contains size of every subtree)
    
public:
    // n = no of nodes in the graph (0-based indexing)
    UnionFindAlgo(int n) {
        parent.resize(n);
        // init the parent[] with parent nodes
        for(int i=0; i<n; i++) parent[i] = i;

        // init rank[] for union by rank 
        // every node is a single tree and the leaf nodes have rank of 0
        rank.resize(n, 0);

        // initially every node is a separate tree with only a single node
        size.resize(n, 1);
    }

    int componentSize(int u) {
        return size[findParent(u)];
    }

    int countComponents() {
        int count = 0;
        for (int i = 0; i < parent.size(); i++) {
            if (parent[i] == i) count++;
        }
        return count;
    }

    int findParent(int x) {
        if (parent[x] != x) {
            parent[x] = findParent(parent[x]); // we do path compression here so that the next findParent() operations run in constant time
        }
        return parent[x];
    }

    bool isConnected(int u, int v) {
        return findParent(u) == findParent(v);
    }

    void unionByRank(int u, int v) {
        // find ultimate parents of u and v
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv) {
            cout << "Nodes " << u << " and " << v << " are already in the same set!" << endl;
            return;
        }

        if (rank[pu] > rank[pv]) {
            // u's tree has higher depth, so attach v to u 
            parent[pv] = pu;
        } else if (rank[pu] < rank[pv]) {
            // v's tree has higher depth than u, so attach u to v
            parent[pu] = pv;
        } else {
            // both have same rank, so same tree depth
            // attach in any order, and increase rank
            parent[pu] = pv;
            rank[pv]++;
        }
    }

    void unionBySize(int u, int v) {
        // find ultimate parents of u and v
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv) {
            cout << "Nodes " << u << " and " << v << " are already in the same set!" << endl;
            return;
        }

        if (size[pu] > size[pv]) {
            // pu has higher number of nodes in it, so higher depth
            // attach v to u
            parent[pv] = pu;
            size[pu] += size[pv];
        } else {
            // 1. pv has higher number of nodes in it, so higher depth
            // So, attach u to v

            // OR, 2. they have the same size, so connection can
            // take place in any order
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }

};

int main() {
    UnionFindAlgo dsu(7);

    dsu.unionByRank(1, 2);
    dsu.unionByRank(2, 3);
    dsu.unionByRank(4, 5);
    dsu.unionByRank(6, 5);
    dsu.unionByRank(3, 5); // joins two components

    cout << (dsu.findParent(2) == dsu.findParent(6) ? "Same component\n" : "Different components\n");
    
    return 0;
}
