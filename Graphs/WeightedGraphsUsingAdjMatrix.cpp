/** Implementation of an Undirected and Directed weighted Graphs using Adjacency Matrix */

#include <iostream>
using namespace std;

int main() {
    constexpr int n = 5;
    int undirected[n][n] = {0};

    int directed[n][n] = {0};

    // Add an edge between 1 and 2 with cost
    undirected[1][2] = 10;
    undirected[2][1] = 10;

    // Add an edge from 3 to 4 with cost but no return path
    directed[3][4] = 2;

    // Print directed
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << directed[i][j] << " ";
        cout << endl;
    }

    // Print undirected
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << undirected[i][j] << " ";
        cout << endl;
    }

    return 0;
}