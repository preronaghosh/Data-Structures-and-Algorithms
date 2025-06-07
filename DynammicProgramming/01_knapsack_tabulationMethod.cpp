
#include <vector>
#include <iostream>
using namespace std;

int knapsack(int& W, vector<int>& wt, vector<int>& val, int& n) {
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0)); // 5 x 6 matrix

    // Build table dp[][] in bottom up manner
    for (int i=1; i<=n; i++) {
        for(int j=1; j<=W; j++) {
            // if current capacity j <= weight of current objet i, 
            // we can take it into the knapsack 
            if (wt[i-1] <= j) {
                // can include
                dp[i][j] = std::max(dp[i-1][j], val[i-1] + dp[i-1][j - wt[i-1]]);

            } else {
                // cannot include
                // carry over same value from previous object at same capacity
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}

int main() {
    vector<int> wt = {1,2,1,2}; // capacity array
    vector<int> val = {6,5,3,8}; // profits array
    int W = 5;
    int n = wt.size(); // 4

    cout << "Maximum value in knapsack: " << knapsack(W, wt, val, n) << endl;
    return 0;
}