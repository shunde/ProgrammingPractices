class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        bool hasAns = false;
        int minLen = INT_MAX;
        
        int sum = 0;
        for (int i = 0, j = 0; i <= j && j < nums.size();j++) {
            sum += nums[j];
            
            while (i <= j && sum >= s) {
                hasAns = true;
                int len = j - i + 1;
                if (len < minLen) minLen = len;
                
                sum -= nums[i];
                i++;
            }
            
        }
        
        
        
        if (hasAns) return minLen;
        else return 0;
        
    }
};