// O(n^2) 
class Solution {
private:
	bool scanFromCenter(const string& s, int l, int r, string &result) {
		int i = 0;
		for (; l - i >= 0; i++) {
			if (s[l - i] != s[r + i]) break;
		}
	
		if (l - i >= 0) return false;
		result = s.substr(r + i);
		reverse(result.begin(), result.end());
		result.append(s);
		return true;
	}
public:
	string shortestPalindrome(string s) {
		if (s.length() <= 1) return s;

		int len = s.length();
		int mid = len / 2;
		string result;

		for (int i = mid; i >= 0; i--) {
			if (scanFromCenter(s, i, i, result)) return result;
			if (scanFromCenter(s, i-1, i, result)) return result;
		}
		return result;
	}
};