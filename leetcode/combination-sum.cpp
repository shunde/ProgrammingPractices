//dfs 
class Solution {
	void combinationSumAux(const vector<int>& sortedNums, int idx, int target, vector<vector<int>>& result, vector<int> curr) {
		if (target == 0 && !curr.empty()) {
			result.push_back(curr);
			return;
		}
		if (target < 0 || idx < 0) return;

		combinationSumAux(sortedNums, idx-1, target, result, curr);
		if (target >= sortedNums[idx]) {
			int count = target / sortedNums[idx];
			int remain = target;
			for (int i = 0; i < count; i++) {
				curr.push_back(sortedNums[idx]);
				remain -= sortedNums[idx];
				combinationSumAux(sortedNums, idx-1, remain, result, curr);
			}
		}
	}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    	vector<vector<int>> result;
    	sort(candidates.begin(), candidates.end());
    	auto itupper = std::upper_bound(candidates.begin(), candidates.end(), target);
    	int idx = std::distance(candidates.begin(), itupper) - 1;

    	combinationSumAux(candidates, idx, target, result, vector<int>());   
    	return result;     
    }
};