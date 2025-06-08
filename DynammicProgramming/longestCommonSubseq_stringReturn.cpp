/* Write a program to find the longest common subsequence of a string using Recursion, Memoization and DP */

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string getLCS(string& s1, string& s2) {
        int m = s1.length();
        int n = s2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Fill dp table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        string lcs="";
        int i = m;
        int j = n;
        // reconstruct the lcs string
        // trace back from dp[m][n] to dp[0][0]
        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                // this was a match
                lcs += s1[i-1];
                i--;
                j--;
            } else {
                if (dp[i-1][j] > dp[i][j-1]) {
                    i--;
                } else j--;
            }
        }
        reverse(lcs.begin(), lcs.end());
        cout << "lcs is: " << lcs << endl;
    }
};

int main() {
    string s1 = "acegxyz";
    string s2 = "abcdefghi";

    Solution sol;
    sol.getLCS(s1, s2);
    
}
