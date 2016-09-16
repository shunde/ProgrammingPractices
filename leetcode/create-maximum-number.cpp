class Solution {
 private:
  vector<int> getMaxSubArray(const vector<int> &nums, int k) {
    vector<int> res(k, 0);
    int len = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      while (len && len + n - i > k && nums[i] > res[len - 1]) {
        len--;
      }
      if (len < k) {
        res[len++] = nums[i];
      }
    }
    return res;
  }
  bool greater(const vector<int> &a, int start1, const vector<int> &b, int start2) {
      for(; start1 < a.size() && start2 < b.size(); start1++, start2++) {
          if (a[start1] > b[start2]) return true;
          if (a[start1] < b[start2]) return false;
      }
      return start1 != a.size();
  }

 public:
  vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
    vector<int> ans(k, 0);
    for (int i = max(0, k - (int)nums2.size()); i <= min(k, (int)nums1.size()); i++) {
      auto res1 = getMaxSubArray(nums1, i);
      auto res2 = getMaxSubArray(nums2, k - i);
      vector<int> res(k, 0);
      int pos1 = 0, pos2 = 0, tpos = 0;
      while (pos1 < res1.size() || pos2 < res2.size()) {
          res[tpos++] = greater(res1, pos1, res2, pos2) ? res1[pos1++]: res2[pos2++];
      }

      if (greater(res, 0, ans, 0)) {
          ans.swap(res);
      }
    }
    return ans;
  }
};
