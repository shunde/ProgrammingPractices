class Solution {
public:
    int numDistinct(string s, string t) {
    	int m = s.length(), n = t.length();
    	if (m < n) return 0;
    	vector<vector<int>> cookie(m, vector<int>(n, -1));
    	return f(s, 0, t, 0, cookie);        
    }
private:
	// 优化--思路
	// 统计字符串每个位置到末尾本字符的个数，这样就可以在分支的时候剪枝
	int f(const string& s, int s_off, const string& t, int t_off, vector<vector<int>>& cookie) {
		int m = s.length(), n = t.length();
		if (t_off >= n) return 1;

		if (cookie[s_off][t_off] == -1) {
			int s_remain = m - s_off;
			int t_remain = n - t_off;
			int ret;
			if (s_remain < t_remain) {
				ret = 0;
			} else if (s_remain == t_remain) {
				ret = !s.compare(s_off, s_remain, t, t_off, t_remain);
			} else {
				ret = f(s, s_off+1, t, t_off, cookie);
				if (s[s_off] == t[t_off])
					ret += f(s, s_off+1, t, t_off+1, cookie);
			}
			cookie[s_off][t_off] = ret;
		}
		return cookie[s_off][t_off];
	}
};