/* Fibonacci numbers using DP tabulation method */

#include <vector>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        dp[1] = 1;

        for (int i=2; i<dp.size(); i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};