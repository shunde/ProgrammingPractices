/**
 * refer to http://jinger8910.blogspot.com/2015/11/burst-balloons.html
 */
class Solution {
public:
	int maxCoins(vector<int>& nums) {
		// nums[-1] = nums[n] = 1;
		nums.insert(nums.begin(), 1);
		nums.push_back(1);
		int n = nums.size();

		vector<vector<int>> dp(n, vector<int>(n, 0));
		for (int k = 2; k < n; k++) {
			for (int left = 0; left < n - k; left++) {
				int right = left + k;
				for (int i = left + 1; i < right; i++) {
					dp[left][right] = max(dp[left][right],
					                      nums[left] * nums[i] * nums[right] + dp[left][i] + dp[i][right]);
				}
			}
		}

		return dp[0][n-1];
	}
};