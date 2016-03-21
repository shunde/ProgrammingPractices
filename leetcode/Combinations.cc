class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > ret;
        vector<int> nums(n, 0);
        for (int i = 0; i < k; i++)
            nums[i] = 1;

        do {
            vector<int> oneComb(k, 0);
            int count = 0;
            for (int i = 0; i < n; i++)
                if (nums[i]) 
                    oneComb[count++] = i+1;

            ret.push_back(oneComb);
        } while (prev_permutation(nums.begin(), nums.end()));

        return ret;
    }
};