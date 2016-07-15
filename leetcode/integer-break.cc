class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        else if (n == 3) return 2;
        else if (n == 4) return 4;
        
        vector<int> dp(n+1, 0);
        dp[2] = 1, dp[3] = 2, dp[4] = 4;
        for (int i = 5; i <= n; i++) {
            dp[i] = 3 * max(dp[i-3], i-3);
        }
        return dp[n];
    }
};