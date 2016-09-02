class Solution {
	void combinationSum2Aux(vector<int>& nums, int idx, int target, vector<vector<int>>& result, vector<int>& curr) {
		if (target == 0 && !curr.empty())
			result.push_back(curr);
		if (idx >= nums.size() || target < nums[idx]) return;

		int new_idx = idx+1;
		// skip nums[idx]
		while (new_idx < nums.size() && nums[new_idx]==nums[new_idx-1]) new_idx++;
		combinationSum2Aux(nums, new_idx, target, result, curr);

		int remain = target - nums[idx];
		curr.push_back(nums[idx]);
		combinationSum2Aux(nums, idx+1, remain, result, curr);
		curr.pop_back();
	}
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    	vector<vector<int>> result;
    	sort(candidates.begin(), candidates.end());

    	vector<int> curr;
    	combinationSum2Aux(candidates, 0, target, result, curr);
    	return result;
        
    }
};