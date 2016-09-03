class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		vector<vector<int>> prev;
		for (int i = 0; i < nums.size(); i++) {
		    
		    // get existing sets
		    if (i == 0 || nums[i] != nums[i-1] || prev.size() == 0) {
		    	// clear prev
		        prev.clear();
		        for (auto& subset: result) {
		            prev.push_back(subset);
		        }
		    }
		    
		    // add current number to each element of the set
		    for (auto& subset: prev) {
		        subset.push_back(nums[i]);
		    }
		    
		    // add each single number as a set, only if current element is different with previous
		    if (i == 0 || nums[i] != nums[i-1]) {
		        prev.push_back(vector<int> {nums[i]});
		    }
		    
		    // add all set created in this iteration
		    for (auto& subset: prev) {
		        result.push_back(subset);
		    }
		}
		// add empty set
		result.push_back(vector<int>());
		return result;
	}
};