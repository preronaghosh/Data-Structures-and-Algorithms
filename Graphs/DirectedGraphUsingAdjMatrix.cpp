/** Implementation of an Directed Unweighted Graph using Adjacency Matrix */

#include <iostream>
using namespace std;

int main() {
    constexpr int n = 5;
    int adj[n][n] = {0};

     // Add an edge from 1 to 2
    adj[1][2] = 1;
    // but no edge from 2 to 1

    // Print matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << adj[i][j] << " ";
        cout << endl;
    }

    return 0;
}