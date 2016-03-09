class Solution {
private:
    int findKth(vector<int>& nums, int low, int high, int k) {
        int i = low, j = high+1;
        int pivot = nums[low];
        while (true) {                // 条件是 while true!!!!!!!!!!!!!!!
            while (nums[++i] < pivot);
            while (nums[--j] > pivot);
            if (i < j) swap(nums[i], nums[j]);
            else break;
        }
        swap(nums[low], nums[j]);
        if (k < j) return findKth(nums, low, j-1, k);
        else if (k > j) return findKth(nums, j+1, high, k);
        else return nums[k];
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKth(nums, 0, nums.size() - 1, nums.size() - k);
    }
};

