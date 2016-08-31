/**
 * refer to http://www.programcreek.com/2014/05/leetcode-first-missing-positive-java/
 */

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    	int n = nums.size();
    	for (int i = 0; i < n; i++) {
    		while (nums[i] != i+1) {
    			if (nums[i] < 1 || nums[i] > n)
    				break;
    			// handle duplicates
    			if (nums[i] == nums[nums[i] - 1])
    				break;

    			swap(nums[i], nums[nums[i]-1]);
    		}
    	}

    	for (int i = 0; i < n; i++) {
    		if (nums[i] != i+1) return i+1;
    	}
    	return n+1;        
    }
};