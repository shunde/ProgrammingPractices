class Solution {
public:
    int rob(vector<int>& nums) {
    	if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];

        int N = nums.size();
        // dp1 rob the first house
        // dp2 not rob the first house
        vector<int> dp1(N, 0);
        vector<int> dp2(N, 0);

        dp1[0] = nums[0];
        dp2[0] = 0;

        dp1[1] = max(dp1[0], nums[1]);
        dp2[1] = max(dp2[0], nums[1]);

        for (int i = 2; i < N; i++) {
            dp1[i] = max(dp1[i-1], dp1[i-2]+nums[i]);
            dp2[i] = max(dp2[i-1], dp2[i-2]+nums[i]);
        }

        return max(dp1[N-2], dp2[N-1]);
        
    }
};