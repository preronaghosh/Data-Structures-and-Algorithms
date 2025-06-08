/* Write a program to find the factorial of N */

#include <iostream>
#include <vector>
using namespace std;

// Recursive approach
int factRecursive(int n) {
    if (n==1) return 1;

    return factRecursive(n-1) * n;
}

// With memoization (top down approach)
int factMemo(int n, vector<int>& memo) {
    if (n==1) {
        memo[n] = 1;
        return 1;
    }

    if (memo[n] != -1) return memo[n];

    memo[n] = factMemo(n-1, memo) * n;
    return memo[n];
}

// With Tabulation method (Bottom up approach)
int factTab(int n) {
    vector<int> dp(n+1, -1);
    dp[1] = 1;
    
    for (int i=2; i<=n; i++) {
        dp[i] = i * dp[i-1];
    }
    return dp[n];
}

// Space optimization
int factLessSpace(int n) {
    int f=1;

    for (int i=2; i<=n; i++) {
        f = f*i;
    }
    return f;
}

int main() {
    int N = 5;
    cout << factRecursive(N) << endl;

    vector<int> memo(N+1, -1); // n value will go from 1 to 5 
    cout << "With memo: " << factMemo(N, memo) << endl;

    cout << "With tabulation method: " << factTab(N) << endl;
    cout << "With space optimization: " << factLessSpace(N) << endl;
}