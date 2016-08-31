class Solution {
public:
    int findPeakElement(vector<int>& nums) {
    	int prev = 1;
    	int peakIdx = -1;
    	for (int i = 1; i < nums.size(); i++) {
    		int curr = nums[i] - nums[i-1];
    		if (prev > 0 && curr < 0) return i-1;
    		prev = curr;
    	}

    	if (prev > 0) {
    		peakIdx = nums.size() - 1;
    	}
    	return peakIdx;        
    }
};