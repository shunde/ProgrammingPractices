class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate;
        int nTimes = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nTimes == 0) {
                candidate = nums[i];
                nTimes = 1;
            } else {
                if (candidate == nums[i])
                    nTimes++;
                else
                    nTimes--;
            }
        }
        return candidate;        
    }
};