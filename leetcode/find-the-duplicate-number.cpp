class Solution {
private:
    // #nums in [lo, hi)
    int countRange(const vector<int>& nums, int lo, int hi) {
        if (lo >= hi) return 0;
        auto count = 0;
        for (auto x: nums) {
            if (x >= lo && x < hi) {
                count++;
            }
        }
        return count;
    }
public:
    int findDuplicate(vector<int>& nums) {
        int low, high;
        // nums in [low, hi)
        low = 1;
        high = nums.size();
        while(true) {
            if (low == high - 1) break;
            int mid = (low + high) / 2;
            int leftCount = countRange(nums, low, mid);
            if (leftCount > mid - low) {
                high = mid;
            } else {
                low = mid;
            }
            
        }
        return low;
    }
};