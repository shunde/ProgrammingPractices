class Solution {
public:
    int rob(vector<int>& nums) {
    	if (nums.empty()) return 0;
    	// dp[0][i] -> not rob house #i
    	// dp[1][i] -> rob house #i
    	int N = nums.size();
    	vector<vector<int>> dp(2, vector<int>(N, 0));

    	dp[0][0] = 0;
    	dp[1][0] = nums[0];
    	for (int i = 1; i < N; i++) {
    		dp[0][i] = max(dp[0][i-1], dp[1][i-1]);
    		dp[1][i] = nums[i] + dp[0][i-1];
    	}

    	return max(dp[0][N-1], dp[1][N-1]);
        
    }
};