class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidates[2] = {0, 0};
        int nTimes[2] = {0, 0};
        for (int i = 0; i < nums.size(); i++) {
            bool flag = false;
            for (int j = 0; j < 2; j++) {
                if (nTimes[j] && candidates[j] == nums[i]) {
                    nTimes[j]++;
                    flag = true;
                    break;
                }
            }

            if (flag) continue;

            for (int j = 0; j < 2; j++) {
                if (nTimes[j] == 0) {
                    candidates[j] = nums[i];
                    nTimes[j] = 1;
                    flag = true;
                    break;
                } 
            }

            if (flag) continue;

            for (int j = 0; j < 2; j++) {
                nTimes[j]--;
            }
        }        
        
        vector<int> result;
        int k = 0;
        for (int i = 0; i < 2; i++) {
            if (nTimes[i] > 0)
                candidates[k++] = candidates[i];
            nTimes[i] = 0;
        }
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < k; j++) {
                if (nums[i] == candidates[j]) {
                    nTimes[j]++;
                    break;
                }                    
            }
        }
        for (int i = 0; i < k; i++) {
            if (nTimes[i] > nums.size()/3)
                result.push_back(candidates[i]);
        }
        return result;        
    }
};