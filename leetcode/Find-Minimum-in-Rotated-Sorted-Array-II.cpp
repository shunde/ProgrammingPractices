class Solution {
private:
    int findMinAux(vector<int>& nums, int left, int right) {
        // only one element left or nums[left] < nums[right]
        if (left == right || nums[left] < nums[right]) return nums[left];
        
        
        // following is nums[left] >= nums[right] cond.
        
        // when array is small
        if (right - left < 3) {
            int minVal = nums[left];
            for (int i = left+1; i <= right; i++) {
                if (minVal > nums[i]) {
                    minVal = nums[i];
                }
            }
            return minVal;
        }
        
        int mid = left + (right - left)/2;
        if (nums[mid] > nums[left]) {
            return findMinAux(nums, mid+1, right);
        } else if (nums[mid] < nums[left]) {
            return findMinAux(nums, left, mid);
        } else { // nums[mid] = nums[left]
            int leftMin = findMinAux(nums, left, mid);
            
            if (leftMin < nums[mid]) return leftMin;
            else return findMinAux(nums, mid, right);
        }
        
    }
public:
    int findMin(vector<int>& nums) {
        return findMinAux(nums, 0, nums.size() - 1);
    }
};