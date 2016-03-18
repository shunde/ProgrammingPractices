class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        vector<int>::iterator iter, iiter, jter;
        
        for (iiter = nums.end() - 1; iiter != nums.begin(); iiter--) {
            if (*(iiter-1) < *iiter)                
                break;                          
        }

        if (iiter == nums.begin()) {
            reverse(nums.begin(), nums.end());
            return;
        }

        iter = iiter - 1;
        for (jter = nums.end() - 1; ; jter--)
            if (*iter < *jter) break;

        swap(*iter, *jter);

        reverse(iiter, nums.end());
    }
};