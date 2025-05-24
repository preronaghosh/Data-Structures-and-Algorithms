/** Implementation of an Undirected Unweighted Graph using Adjacency Matrix */

#include <iostream>
using namespace std;

int main() {
    constexpr int n = 5;
    int adj[n][n] = {0};

     // Add an edge between 1 and 2
    adj[1][2] = 1;
    adj[2][1] = 1; // undirected

    // Print matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << adj[i][j] << " ";
        cout << endl;
    }

    return 0;
}