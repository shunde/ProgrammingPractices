class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	if (nums.size() < 2) return nums.size();
    	vector<int> dp(nums.size());
    	int ret;
    	ret = dp[0] = 1;
    	for (int i = 1; i < nums.size(); i++) {
    		int seqLen = 0;
    		for (int j = 0; j < i; j++) {
    			if (nums[j] < nums[i] && dp[j] > seqLen)
    				seqLen = dp[j];
    		}
    		dp[i] = seqLen + 1;
    		if (ret < dp[i])
    			ret = dp[i];
    	}
    	return ret;        
    }
};