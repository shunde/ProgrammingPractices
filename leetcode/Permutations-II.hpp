class Solution {
private:
    void permuteAux(vector<int>& nums, int index, vector<vector<int> >& result) {
        if (index == nums.size()) {            
            result.push_back(vector<int> (nums.begin(), nums.end()));
        }

        for (int start = index; start < nums.size(); start++) {
           
            bool duplicated = false;
            for (int i = start - 1; i >= index; i--)
                if (nums[i] == nums[start]) {
                    duplicated = true;
                    break;
                }
            if (duplicated) continue;

            swap(nums[index], nums[start]);
            permuteAux(nums, index+1, result);
            swap(nums[index], nums[start]);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > result;
        if (!nums.empty()) {
            permuteAux(nums, 0, result);
        }        
        return result;        
    }
};

