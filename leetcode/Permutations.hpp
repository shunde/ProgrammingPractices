/**
 * 将数组中第一个数和后面所有的数交换，然后求后面的排列。
 * 问题一步一步变小。
 */

class Solution {
private:
    void permuteAux(vector<int>& nums, int index, vector<vector<int> >& result) {
        if (index == nums.size()) {            
            result.push_back(vector<int> (nums.begin(), nums.end()));
        }

        for (int start = index; start < nums.size(); start++) {
            swap(nums[index], nums[start]);
            permuteAux(nums, index+1, result);
            swap(nums[index], nums[start]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > result;
        if (!nums.empty()) {
            permuteAux(nums, 0, result);
        }        
        return result;        
    }
};