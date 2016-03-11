/**
 * Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. 
 * Find the two elements that appear only once.
 * For example:
 * 
 * Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
 */

class Solution {
private:
    int first1bit(int n) {
        int mask = 0x01;
        for (int i = 0; i < sizeof(n) * 8; i++) {
            if (n & mask)
                return i;
            mask <<= 1;
        }
        return -1; // no bit 1
    }
public:
    vector<int> singleNumber(vector<int>& nums) {
        int num_xor = 0;
        for (int i = 0; i < nums.size(); i++)
            num_xor ^= nums[i];

        int index1 = first1bit(num_xor);
        int mask = 0x01 << index1;

        vector<int> result = vector<int>(2, 0);

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & mask)
                result[0] ^= nums[i];
            else
                result[1] ^= nums[i];
        }

        return result;
    }
};