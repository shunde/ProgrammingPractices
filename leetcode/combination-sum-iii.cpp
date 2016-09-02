class Solution {
	void combinationSum3Aux(int num, int k, int target, vector<vector<int>>& result, vector<int>& curr) {
		if (target == 0 && k == 0 && !curr.empty()) {
			result.push_back(curr);
			return;

		}

		int minSum = (num + num + k-1)*k/2;
		if (num > 9 || k == 0 || target < minSum) return;

		// contain num
		curr.push_back(num);
		combinationSum3Aux(num+1, k-1, target-num, result, curr);
		curr.pop_back();

		// skip num
		combinationSum3Aux(num+1, k, target, result, curr);
	}
public:
    vector<vector<int>> combinationSum3(int k, int n) {
    	vector<vector<int>> result;
    	vector<int> curr;

    	combinationSum3Aux(1, k, n, result, curr);
    	return result; 
        
    }
};