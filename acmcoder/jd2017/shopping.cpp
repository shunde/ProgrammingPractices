#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

void solve(vector<int>& costs, vector<string>& goods) {
      sort(costs.begin(), costs.end());
      unordered_map<string, int> mymap;
      for (auto& str: goods) {
            mymap[str]++;
      }
      vector<int> nums;
      for (auto& item: mymap) {
            nums.push_back(item.second);
      }
      sort(nums.begin(), nums.end(), greater<int>());
      long long minfee = 0, maxfee = 0;
     
      for (int i = 0; i < nums.size(); i++) {
            minfee += costs[i] * nums[i];
            maxfee += costs[costs.size() - i - 1] * nums[i];
      }
      cout << minfee << " " << maxfee << endl;
}

int main() {
      int n, m;
      while (cin >> n >> m) {
            vector<int> costs(n);
            vector<string> goods(m);
            for (int i = 0; i < n; i++)
                  cin >> costs[i];
            for (int i = 0; i < m; i++) {
                  string input;
                  cin >> input;
                  goods[i] = input;

            }
            solve(costs, goods);
      }
      return 0;
}