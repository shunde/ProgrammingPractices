// divided and conquer
// Time Limit Exceeded
class Solution {
  int countRangeSumHelper(const vector<int>& nums, const vector<long long>& acc,
                          int left, int right, int lower, int upper) {
    if (left > right)
      return 0;
    else if (left == right) {
      if (nums[left] >= lower && nums[left] <= upper) return 1;
      return 0;
    }
    int mid = (left + right) >> 1;
    int total = 0;
    for (int i = mid; i >= left; i--) {
      for (int j = mid + 1; j <= right; j++) {
        long long sum = acc[j] - acc[i] + nums[i];
        if (sum >= lower && sum <= upper) total++;
      }
    }
    return total + countRangeSumHelper(nums, acc, left, mid, lower, upper) +
           countRangeSumHelper(nums, acc, mid + 1, right, lower, upper);
  }

 public:
  int countRangeSum(vector<int>& nums, int lower, int upper) {
    if (nums.empty() || lower > upper) return 0;
    int n = nums.size();
    vector<long long> acc(n, 0);
    acc[0] = nums[0];
    for (int i = 1; i < n; i++) {
      acc[i] = acc[i - 1] + nums[i];
    }
    return countRangeSumHelper(nums, acc, 0, n - 1, lower, upper);
  }
};