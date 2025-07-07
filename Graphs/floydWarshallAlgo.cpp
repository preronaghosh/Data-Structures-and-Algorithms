#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

const int INF = 1e9;  // A large number representing infinity

void floydWarshall(vector<vector<int>>& dist, int n) {
    // Floyd-Warshall Algorithm using 2D - DP approach
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Detect negative weight cycles
    for (int i = 0; i < n; ++i) {
        if (dist[i][i] < 0) {
            cout << "Negative weight cycle detected at node " << i << endl;
            return;
        }
    }

    // Print the shortest distance matrix
    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INF)
                cout << "INF" << setw(5);
            else
                cout << dist[i][j] << setw(5);
        }
        cout << "\n";
    }
}

int main() {
    int n = 4;  // Number of vertices

    // Initialize adjacency matrix
    // INF means no direct edge
    vector<vector<int>> dist = {
        {0,    3,   INF,   7},
        {8,    0,   2,     INF},
        {5,    INF, 0,     1},
        {2,    INF, INF,   0}
    };

    floydWarshall(dist, n);

    return 0;
}
