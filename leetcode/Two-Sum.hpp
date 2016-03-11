/**
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution.
 * 
 * Analysis:
 * use hashmap to record number index, since each input would have exactly one solution, we can record index xor.
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result = vector<int> (2, 0);
        map<int, int> indices;

        for (int i = 0; i < nums.size(); i++) {
            if (indices.find(nums[i]) != indices.end()) {
                indices[nums[i]] = i ^ indices[nums[i]];
            } else {
                indices[nums[i]] = i;
            }
        }
        
        for (int i = 0; i < nums.size(); i++) {
            int num1 = nums[i];
            int num2 = target - num1;
            if (indices.find(num2) != indices.end()) {
                if (num1 == num2 && indices[num2] != i) {
                    result[0] = i;
                    result[1] = i ^ indices[num2];
                    break;
                } else if (num1 != num2) {
                    result[0] = i;
                    result[1] = indices[num2];
                    break;
                }
            }            
        }
        return result;                              
    }
};