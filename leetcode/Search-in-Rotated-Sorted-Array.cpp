class Solution {
    int searchAux(vector<int>& nums, int target, int left, int right) {
        // small array
        if (right - left <= 3) {
            for (int i = left; i <= right; i++)
                if (nums[i] == target) return i;
            return -1; // not found.
        }

        // not rotated
        if (nums[left] < nums[right]) {
            int mid = left + (right - left) / 2;
            if (target < nums[mid])
                return searchAux(nums, target, left, mid - 1);
            else if (target > nums[mid])
                return searchAux(nums, target, mid + 1, right);
            else 
                return mid;
        } else {
            int mid = left + (right - left) / 2;
            if (nums[left] < nums[mid]) {
                if (target >= nums[left] && target <= nums[mid])
                    return searchAux(nums, target, left, mid);
                else
                    return searchAux(nums, target, mid+1, right);
            } else {
                if (target >= nums[left] || target <= nums[mid])
                    return searchAux(nums, target, left, mid);
                else 
                    return searchAux(nums, target, mid+1, right);
            }
        }
        
    }
public:
    int search(vector<int>& nums, int target) {
        return searchAux(nums, target, 0, nums.size() - 1);
    }
};
