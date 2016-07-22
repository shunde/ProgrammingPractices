class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
    	int n = nums.size();
    	if (n <= 1) return n; 
    	int gradient = 0;
    	int segment = 0;
    	for (int i = 1; i < n; i++) {
    		int diff = nums[i] - nums[i-1];
    		if (diff == 0 || gradient * diff > 0)
    			continue;
    		else if (gradient == 0) {
    			gradient = diff;
    			segment = 1;
    		} else if (gradient * diff < 0) {
    			segment++;
    			gradient = diff;
    		}
    	}
    	return segment+1;        
    }
};