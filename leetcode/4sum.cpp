class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        
        if (nums.size() < 4) return result;
    	
    	sort(nums.begin(), nums.end());
        
    	for (int i = 0; i < nums.size() - 3; i++) {
    		if (i != 0 && nums[i] == nums[i-1])
    			continue;
    		for (int j = i + 1; j < nums.size() - 2; j++) {
    			if (j != i + 1 && nums[j] == nums[j-1])
    				continue;

    			int k = j + 1;
    			int m = nums.size() - 1;
    			while (k < m) {
    				int sum = nums[i] + nums[j] + nums[k] + nums[m];
    				if (sum == target) {
    					result.push_back(vector<int> {nums[i], nums[j], nums[k], nums[m]});
    					k++;
    					m--;
    					while (k < m && nums[k] == nums[k-1]) k++;
    					while (k < m && nums[m] == nums[m+1]) m--;
    				} else if (sum < target) {
    					k++;
    				} else {
    					m--;
    				}
    			}
    		}
    	}
    	return result;        
    }
};