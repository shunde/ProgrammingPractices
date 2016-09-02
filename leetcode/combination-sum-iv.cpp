// refer to http://www.programcreek.com/2014/07/leetcode-combination-sum-iv-java/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (target <= 0 || nums.empty()) return 0;
        vector<int> dp(target+1);
        dp[0] = 1;
        
        for (int i = 0; i < target; i++) {
            for (auto x: nums) {
                if (i+x <= target) {
                    dp[i+x] += dp[i];
                }
            }
        }
        return dp[target];
        
        
    }
};

// Time Limit Exceeded
// class Solution {
// private:
// 	void combinationSum4Aux(vector<int>& nums, int idx, int target, int& cnt, vector<int> curr) {
// 		if (target == 0 && !curr.empty()) {
// 			do {
// 				cnt++;
// 			} while(next_permutation(curr.begin(), curr.end()));
// 			return;
// 		}
// 		if (idx == nums.size() || target < nums[idx]) return;

// 		vector<int> v = curr;
// 		int remain = target;
// 		for (int i = 0; i < target / nums[idx]; i++) {
// 			v.push_back(nums[idx]);
// 			remain -= nums[idx];
// 			combinationSum4Aux(nums, idx+1, remain, cnt, v);
// 		}
// 		// skip nums[i]
// 		combinationSum4Aux(nums, idx+1, target, cnt, curr);
// 	}

// public:
//     int combinationSum4(vector<int>& nums, int target) {
//     	sort(nums.begin(), nums.end());
//     	int result;
//     	vector<int> curr;
//     	combinationSum4Aux(nums, 0, target, result, curr);

//     	return result;
        
//     }
// };