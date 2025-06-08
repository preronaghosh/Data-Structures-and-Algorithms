/* Write a program to find the length of the longest common subsequence of a string or array using Recursion */

#include <string>
#include <iostream>
#include <vector>
using namespace std;

// Recursive solution
int lengthOfLCS(int i, int j, string& s1, string& s2) {
    if (i == 0 || j == 0) return 0;

    if (s1[i] == s2[j]) {
        return 1 + lengthOfLCS(i-1, j-1, s1, s2);
    } else {
        return max(lengthOfLCS(i-1, j, s1, s2), lengthOfLCS(i, j-1, s1, s2));
    } 
}

// With memoization
int lengthOfLCSWithMemo(int i, int j, string& s1, string& s2, vector<vector<int>>& memo) {
    if (i == 0 || j == 0) {
        memo[i][j] = 0;
        return 0;
    }

    if (memo[i][j] != -1) return memo[i][j];

    if (s1[i-1] == s2[j-1]) {
        memo[i-1][j-1] = lengthOfLCSWithMemo(i-1, j-1, s1, s2, memo);
        memo[i][j] = 1 + memo[i-1][j-1];
    } else {
        memo[i-1][j] = lengthOfLCSWithMemo(i-1, j, s1, s2, memo);
        memo[i][j-1] = lengthOfLCSWithMemo(i, j-1, s1, s2, memo);
        memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
    }
    return memo[i][j];
}

// tabulation method
int lengthOfLCS_DP(string& s1, string& s2) {
    if (s1.empty() || s2.empty()) return 0;
    
    int l1 = s1.length();
    int l2 = s2.length();

    vector<vector<int>> dp(l1+1, vector<int>(l2+1, -1));
    dp[0][0] = 0;

    for (int i=1; i<=l1; i++) {
        for (int j=1; j<=l2; j++) {
            if (s1[i-1] == s2[j-1]) { // since the string is 0-based indexed
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[l1][l2];
}

int main() {
    string s1 = "ace";
    string s2 = "abcde";

    cout << "Recursive solution: " << lengthOfLCS(s1.length(), s2.length(), s1, s2) << endl;

    vector<vector<int>> memo(s1.length()+1, vector<int>(s2.length()+1, -1));
    cout << "Result with memoization: " << lengthOfLCSWithMemo(s1.length(), s2.length(), s1, s2, memo) << endl;

    vector<vector<int>> dp(s1.length()+1, vector<int>(s2.length()+1, -1));
    cout << "Result with dp tabulation method: " << lengthOfLCS_DP(s1, s2) << endl;
}


