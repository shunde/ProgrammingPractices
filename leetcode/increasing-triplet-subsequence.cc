class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
    	int n = nums.size();
    	if (n < 3) return false;
    	int cur, min;
    	int count;
    	min = cur = nums[0];        
    	count = 1;

    	for (int i = 1; i < n; i++) {
    		if (cur < nums[i]) {
    			min = cur;
    			cur = nums[i];
    			count++;
    		} else if (cur > nums[i]) {
    			if (count == 1) {
    				min = cur = nums[i];    				
    			}
    		}
    	}
    	return false;
    }
};