class Solution {
 private:
  struct NumsInfo {
    int start;
    int size;
    int pos;
    NumsInfo() : start(0), pos(0), size(0) {}
  };
  unordered_map<int, NumsInfo> mymap;
  vector<int> idxs;

 public:
  Solution(vector<int> nums) {
    int n = nums.size();
    idxs.resize(n, 0);
    for (auto x : nums) {
      mymap[x].size++;
    }
    int countSofar = 0;
    for (auto& item : mymap) {
      item.second.pos = item.second.start = countSofar;
      countSofar += item.second.size;
    }
    for (int i = 0; i < nums.size(); i++) {
      auto& info = mymap[nums[i]];
      idxs[info.pos++] = i;
    }
  }

  int pick(int target) {
    const auto& info = mymap[target];
    int idx = info.start + (rand() % info.size);
    return idxs[idx];
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */