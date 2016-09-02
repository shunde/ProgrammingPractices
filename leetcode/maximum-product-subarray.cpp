class Solution {
public:
    int maxProduct(vector<int>& nums) {
    	int n = nums.size();
    	if (n == 0) return 0;
    	vector<int> maxdp(n, 0);
    	vector<int> mindp(n, 0);
    	int result;
    	result = maxdp[0] = mindp[0] = nums[0];

    	for (int i = 1; i < n; i++) {
    		if (nums[i] > 0) {
    			maxdp[i] = max(nums[i], maxdp[i-1]*nums[i]);
    			mindp[i] = min(nums[i], mindp[i-1]*nums[i]);
    		} else {
    			maxdp[i] = max(nums[i], mindp[i-1]*nums[i]);
    			mindp[i] = min(nums[i], maxdp[i-1]*nums[i]);
    		}
    		result = max(maxdp[i], result);
    	}   
    	return result; 	    	        
    }
};