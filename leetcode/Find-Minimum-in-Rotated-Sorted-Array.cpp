class Solution {
private:
    int _findMin_aux(vector<int>& nums, int left, int right) {
        if (nums[left] <= nums[right]) return nums[left];
        int mid = left + (right - left) / 2;
        if (nums[mid] >= nums[left]) return _findMin_aux(nums, mid+1, right);
        else return _findMin_aux(nums, left, mid);
    }
public:
    // asume no duplicate 
    int findMin(vector<int>& nums) {
        return _findMin_aux(nums, 0, nums.size() - 1);
    }
};