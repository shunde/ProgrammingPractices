// refer to http://www.programcreek.com/2014/03/leetcode-word-break-ii-java/
// This problem is very similar to Word Break. 
// Instead of using a boolean array to track the matched positions, 
// we need to track the actual matched words. 
// Then we can use depth first search to get all the possible paths
class Solution {
private:
	void dfs(const vector<vector<string>>& dp, int end, vector<string>& result, const string& suffix) {
		if (end <= 0) {
			if (!suffix.empty()) {
				result.push_back(suffix);				
			}			
			return;
		}
		for (auto& word: dp[end]) {
			string combined = word;
			if (!suffix.empty())
				combined += " " + suffix;
			dfs(dp, end - word.length(), result, combined);
		}
	}
public:

	vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
		int len = s.length();
		vector<vector<string>> dp(len + 1);
		// make dp[0] not empty
		dp[0].push_back("#");
		
		for (int j = 1; j <= len; j++) {
			for (int i = 0; i < j; i++) {
				if (!dp[i].empty() && wordDict.find(s.substr(i, j-i)) != wordDict.end()) {
					dp[j].push_back(s.substr(i, j-i));
				}
			}
		}

		vector<string> result;
		if (len == 0 || dp[len].empty()) return result;
		
		dfs(dp, len, result, "");

		return result;		
	}
};


// Time Limit Exceeded Again
// class Solution {
// public:
// 	vector<string> wordBreak(string s, unordered_set<string>& wordDict) {

// 		if (s.empty()) return vector<string> ();
// 		int n = s.length();
// 		vector<vector<unordered_set<string>>> dp(n, vector<unordered_set<string>>(n));
// 		for (int t = 0; t < s.length(); t++) {
// 			for (int i = 0; i < s.length() - t; i++) {
// 				int j = i + t;
// 				if (wordDict.find(s.substr(i, j - i + 1)) != wordDict.end())
// 					dp[i][j].insert(s.substr(i, j - i + 1));
// 				for (int k = i + 1; k <= j; k++) {
// 					if (!dp[i][k - 1].empty() && !dp[k][j].empty()) {
// 						for (auto& str1 : dp[i][k - 1]) {
// 							for (auto& str2 : dp[k][j]) {
// 								dp[i][j].insert(str1 + " " + str2);
// 							}
// 						}
// 					}
// 				}
// 			}
// 		}
// 		return vector<string> (dp[0][n - 1].begin(), dp[0][n - 1].end());
// 	}
// };



// Time Limit Exceeded
// class Solution {
// public:
//     vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
//     	unordered_set<string> myset;
//     	if (s.empty()) return vector<string> ();
//     	if (wordDict.find(s) != wordDict.end())
//     		myset.insert(s);


//     	for (int i = 1; i < s.length(); i++)  {
//     		vector<string> leftResult = wordBreak(s.substr(0, i), wordDict);
//     		if (!leftResult.empty()) {
//     			vector<string> rightResult = wordBreak(s.substr(i), wordDict);
//     			if (!rightResult.empty()) {
//     				for (auto& str1: leftResult) {
//     					for (auto& str2: rightResult) {
//     						myset.insert(str1 + " " + str2);
//     					}
//     				}
//     			}
//     		}
//     	}
//     	return vector<string>(myset.begin(), myset.end());
//     }
// };