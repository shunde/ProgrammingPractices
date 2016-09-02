class Solution {
public:
	// dp 
    bool wordBreak(string s, unordered_set<string>& wordDict) {
    	int len = s.length();
    	vector<bool> dp(len+1, false);
    	dp[len] = true;

    	for (int i = len-1; i >= 0; i--) {
    		for (int j = len - 1; j >= i; j--) {
    			// the condition order is key issue.
    			if (dp[j+1] && wordDict.find(s.substr(i, j-i+1)) != wordDict.end()) {
    				dp[i] = true;
    				break;
    			}
    		}
    	}

    	return dp[0];        
    }
};