/**
 * 给一个正整数 n, 找到若干个完全平方数(比如1, 4, 9, ... )使得他们的和等于 n。你需要让平方数的个数最少。
 * 给出 n = 12, 返回 3 因为 12 = 4 + 4 + 4。
 * 给出 n = 13, 返回 2 因为 13 = 4 + 9。
 **/
 #include <iostream>
 #include <algorithm>
 #include <climits>
 #include <cmath>
 #include <vector>
 using namespace std;

int minSquare(int n) {
	int rootOfN = sqrt(n);
	vector<int> dp(n+1, INT_MAX);
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= rootOfN; j++) {
			if (i == j*j) {
				dp[i] = 1;
				break;
			} else if (i > j*j) {
				dp[i] = min(dp[i], dp[i-j*j]+1);
			} else {
				// case i < j*j
				// quit for-loop
				break;
			}
		}
	}
	return dp[n];
}

int main() {
	int N = 20;
	for (int i = 1; i <= N; i++) {
		cout << "n = " << i;
		cout << ", return " << minSquare(i) << endl;
	}
	return 0;
}