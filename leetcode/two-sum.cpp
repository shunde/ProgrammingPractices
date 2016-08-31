class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2, 0);
        unordered_map<int, int> my_map;
        for (int i = 0; i < nums.size(); i++) {
            if (my_map.find(nums[i]) != my_map.end()) {
                int index = my_map[nums[i]];
                result[0] = index;
                result[1] = i;
                break;
            } else {
                my_map[target - nums[i]] = i;
            }
        }
        return result;
    }
};
