// dp
// refer to
// https://soulmachine.gitbooks.io/algorithm-essentials/content/java/dp/scramble-string.html

class Solution {
public:
	bool isScramble(string s1, string s2) {
		if (s1.length() != s2.length()) return false;
		if (s1.compare(s2) == 0) return true;

		vector<int> count(26, 0);
		for (auto c : s1) {
			count[c - 'a']++;
		}
		for (auto c : s2) {
			count[c - 'a']--;
		}
		for (auto x : count) {
			if (x != 0) return false;
		}

		int N = s1.length();
		// dp[n][i][j] -> 长度为 n, 起点为 s1[i] 和 s2[j] 的字符串是否为 scramble
		vector<vector<vector<bool>>> dp(
		    N + 1, vector<vector<bool>>(N, vector<bool>(N, false)));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dp[1][i][j] = (s1[i] == s2[j]);
			}
		}

		for (int n = 2; n <= N; n++) {
			for (int i = 0; i <= N - n; i++) {
				for (int j = 0; j <= N - n; j++) {
					for (int k = 1; k < n; k++) {
						// 状态转移方程
						dp[n][i][j] = dp[n][i][j] || ((dp[k][i][j] && dp[n - k][i + k][j + k]) ||
						                              (dp[k][i][j + n - k] && dp[n - k][i + k][j]));
					}
				}
			}

		}
		return dp[N][0][0];

	}
};