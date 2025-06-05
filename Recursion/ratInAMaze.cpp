/* Write a program to solve the Rat in a Maze problem */

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
    vector<string> solutions;
public:
    void backtrack(int row, int col, vector<vector<int>>& maze, int n, string& path, vector<vector<bool>>& visited) {
        if (row == n - 1 && col == n - 1) {
            solutions.push_back(path);
            return;
        }

        visited[row][col] = true;

        const vector<pair<string, pair<int, int>>> dirsMap = {
            {"R", {0, 1}},
            {"D", {1, 0}},
            {"L", {0, -1}},
            {"U", {-1, 0}},
        };

        for (auto dir : dirsMap) {
            string nextDir = dir.first;
            int dr = dir.second.first;
            int dc = dir.second.second;
            int nr = row + dr;
            int nc = col + dc;

            if (nr >= 0 && nc >= 0 && nr < n && nc < n && !visited[nr][nc] && maze[nr][nc] == 1) {
                path += nextDir;
                backtrack(nr, nc, maze, n, path, visited);
                path.pop_back(); // remove the current direction and try next direction
                // don't unmark viisted = false yet 
            }
        }
        // bakctrack visited here after all directions have been checked 
        // so that new valid paths from source to dest can be found again
        visited[row][col] = false;       
    }


    vector<string> findPath(vector<vector<int>>& maze, int n) {
        if (maze[0][0] == 0) return {};
        string path = "";
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        backtrack(0, 0, maze, n, path, visited);
        return solutions;
    }

};


int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    // expected output: [ "DRDDRR" ]
    Solution solver;
    auto result = solver.findPath(maze, 4);
    
    cout << "[ ";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << "\"" << result[i] << "\"";
        if (i < result.size() - 1) cout << ", ";
    }
    cout << " ]" << endl;

    return 0;
}
