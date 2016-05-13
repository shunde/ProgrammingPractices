class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {    	
    	vector<int> result;
    	if (nums.size() == 0) return result;    	
    	int start, end, maxIdx; // [start, end)
    	maxIdx = start = 0, end = k;
    	for (int i = 1; i < k; i++) {
    		if (nums[i] >= nums[maxIdx])
    			maxIdx = i;
    	}
    	result.push_back(nums[maxIdx]);
    	for (int i = k; i < nums.size(); i++) {
    		start++;
    		end++;
    		if (nums[i] >= nums[maxIdx])
    			maxIdx = i;
    		if (maxIdx < start) {
    			maxIdx = start;
    			for (int idx = start+1; idx < end; idx++) {
    				if (nums[idx] >= nums[maxIdx])
    					maxIdx = idx;
    			}
    		}
    		result.push_back(nums[maxIdx]);
    	} 
    	return result;      
    }
};