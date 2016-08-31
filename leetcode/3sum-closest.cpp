class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    	int minDiff = INT_MAX;
    	int result = 0;
    	sort(nums.begin(), nums.end());
    	for (int i = 0; i < nums.size() - 2; i++) {
    		if (i != 0 && nums[i] == nums[i-1])
    			continue;
    		int j = i + 1; 
    		int k = nums.size() - 1;
    		while (j < k) {
    			int sum = nums[i] + nums[j] + nums[k];

    			if (sum == target) return sum;

    			int diff = abs(target - sum);
    			if (diff < minDiff) {
    				minDiff = diff;
    				result = sum;
    			}

    			if (sum > target) k--;
    			if (sum < target) j++;
    		}
    	}
    	return result;        
    }
};