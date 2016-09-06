// refer to https://www.hrwhisper.me/leetcode-count-of-range-sum/
class Solution {
  typedef long long int64;
  struct SegmentTreeNode {
    int64 L, R;
    int cnt;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int64 L, int64 R)
        : L(L), R(R), cnt(0), left(NULL), right(NULL) {}
  };

  class SegmentTree {
   public:
    SegmentTree(const vector<int64> &nums, int l, int r) {
      root = buildSegmentTree(nums, l, r);
    }
    void update(int64 val) { update(root, val); }
    int sum(int64 L, int64 R) { return sum(root, L, R); }

   private:
    SegmentTreeNode *buildSegmentTree(const vector<int64> &nums, int l, int r) {
      if (l > r) return NULL;
      SegmentTreeNode *root = new SegmentTreeNode(nums[l], nums[r]);
      if (l == r) return root;  // important
      int mid = (l + r) >> 1;
      root->left = buildSegmentTree(nums, l, mid);
      root->right = buildSegmentTree(nums, mid + 1, r);
      return root;
    }
    void update(SegmentTreeNode *root, int64 val) {
      if (root && val >= root->L && val <= root->R) {
        root->cnt++;
        update(root->left, val);
        update(root->right, val);
      }
    }
    int sum(SegmentTreeNode *root, int64 L, int64 R) {
      if (!root || L > root->R || R < root->L) return 0;
      if (L <= root->L && R >= root->R) return root->cnt;
      return sum(root->left, L, R) + sum(root->right, L, R);
    }

   private:
    SegmentTreeNode *root;
  };

 public:
  int countRangeSum(vector<int> &nums, int lower, int upper) {
    if (nums.empty() || lower > upper) return 0;
    int n = nums.size();
    vector<int64> acc(n, 0);
    acc[0] = nums[0];
    for (int i = 1; i < n; i++) {
      acc[i] = acc[i - 1] + nums[i];
    }
    int64 sum = acc[n - 1];
    sort(acc.begin(), acc.end());
    auto it = unique(acc.begin(), acc.end());
    SegmentTree tree(acc, 0, it - acc.begin() - 1);

    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
      tree.update(sum);
      sum -= nums[i];
      ans += tree.sum(lower + sum, upper + sum);
    }
    return ans;
  }
};

// divided and conquer
// Time Limit Exceeded
// class Solution {
//   int countRangeSumHelper(const vector<int>& nums, const vector<long long>&
//   acc,
//                           int left, int right, int lower, int upper) {
//     if (left > right)
//       return 0;
//     else if (left == right) {
//       if (nums[left] >= lower && nums[left] <= upper) return 1;
//       return 0;
//     }
//     int mid = (left + right) >> 1;
//     int total = 0;
//     for (int i = mid; i >= left; i--) {
//       for (int j = mid + 1; j <= right; j++) {
//         long long sum = acc[j] - acc[i] + nums[i];
//         if (sum >= lower && sum <= upper) total++;
//       }
//     }
//     return total + countRangeSumHelper(nums, acc, left, mid, lower, upper) +
//            countRangeSumHelper(nums, acc, mid + 1, right, lower, upper);
//   }
//
//  public:
//   int countRangeSum(vector<int>& nums, int lower, int upper) {
//     if (nums.empty() || lower > upper) return 0;
//     int n = nums.size();
//     vector<long long> acc(n, 0);
//     acc[0] = nums[0];
//     for (int i = 1; i < n; i++) {
//       acc[i] = acc[i - 1] + nums[i];
//     }
//     return countRangeSumHelper(nums, acc, 0, n - 1, lower, upper);
//   }
// };