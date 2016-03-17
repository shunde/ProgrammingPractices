class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        int n;
        if (!(n = nums.size())) return result;
        int left, right;

        // lower bound
        left = 0, right = n - 1;
        while (true) {
            int mid = left + (right - left) / 2;
            if (target <= nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
            
            if (left > right)
                break;
        }

        if (nums[left] == target)
            result[0] = left;
        else    
            return result;

        // upper bound
        right = n - 1;
        while (true) {
            int mid = left + (right - left) / 2;
            if (target >= nums[mid])
                left = mid + 1;                
            else
                right = mid - 1;                            

            if (left > right)
                break;
        }

        if (nums[right] == target)
            result[1] = right;
        else    
            return result;



    }
};