/* Knapsack problem solution using recursion and memoization */

#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

// n is 0-based indexed
int knapsack(int n, int W, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp) {
    // if we have reached last object OR capacity over
    if (n==0 || W == 0) {
        dp[n][W] = 0;
        return 0;
    }

    if (dp[n][W] != -1) return dp[n][W];

    // do not check <= 0 because going to 0 is fine here
    // it just means that including this object will make it the last one being added to the sack
    if (W - wt[n-1] < 0) { 
        // prevent recursive calls for when capacity has been exhausted
        dp[n][W] = knapsack(n-1, W, wt, val, dp);
    }

    // include this object and later add the profit of taking this one
    int include = knapsack(n-1, W - wt[n-1], wt, val, dp) + val[n-1];
    // exclude this object
    int exclude = knapsack(n-1, W, wt, val, dp);
    dp[n][W] = max(include, exclude);

    return dp[n][W];
}

int main() {
    vector<int> weights = {1,2,1,2};
    vector<int> values = {6,5,3,8};
    int W = 5;
    int n = weights.size();

    // Create a memo matrix (n x W) to store the result of every combo of the recursive call
    vector<vector<int>> dp(n+1, vector<int>(W+1, -1));

    auto start = std::chrono::high_resolution_clock::now();
    int maxValue = knapsack(n, W, weights, values, dp);
    auto end = std::chrono::high_resolution_clock::now();

    cout << "Maximum value in Knapsack = " << maxValue << endl;

    cout << "Time taken: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << endl; // need to add more weights and profits

    return 0;
}
