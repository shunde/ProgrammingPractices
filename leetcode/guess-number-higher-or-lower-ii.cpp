class Solution {
public:
	int getMoneyAmount(int n) {
		vector<vector<int>> cookie(n + 1, vector<int>(n + 1, 0));
		return f(1, n, cookie);
	}
private:
	int f(int lo, int hi, vector<vector<int>> &cookie) {
		if (lo >= hi) return 0;
		if (hi - lo == 1) return lo;
		if (hi - lo == 2) return lo + 1;

		if (cookie[lo][hi] == 0) {
			int minCost = INT_MAX;
			int cost;
			for (int i = lo + 1; i < hi; i++) {
				cost = i;
				cost += max(f(lo, i - 1, cookie), f(i + 1, hi, cookie));
				minCost = min(minCost, cost);
			}
			cookie[lo][hi] = minCost;
		}

		return cookie[lo][hi];
	}
};