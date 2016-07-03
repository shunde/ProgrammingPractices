class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
    	if (nums.size() < 2) return nums;
    	sort(nums.begin(), nums.end());
    	size_t n = nums.size();
    	vector<int> dp(n, 1);
    	vector<int> trace(n, -1);
    	int largestSofar = 1;
    	int largestIdxSofar = 0;
    	vector<int> subset;
    	
    	return subset;        
    }
};