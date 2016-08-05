class Solution {

public:
    vector<string> removeInvalidParentheses(string s) {
    	vector<string> result;
    	int max = 0;
    	std::function<void(string,string,int,int)> dfs;
    	dfs = [&](string str, string remained, int countLeft, int maxLeft) {
    		if (str.length() == 0) {
    			if (countLeft == 0 && remained.length() != 0) {
    				if (maxLeft > max) max = maxLeft;
    				if (max == maxLeft && find(result.begin(), result.end(), remained) == result.end()) {
    					result.push_back(remained);
    				}
    			}
    			return;
    		}

    		if (str[0] == '(') {
    			dfs(str.substr(1), remained + '(', countLeft+1, maxLeft+1);
    			dfs(str.substr(1), remained, countLeft, maxLeft);
    		} else if (str[0] == ')') {
    			if (countLeft > 0) {
    				dfs(str.substr(1), remained + ')', countLeft-1, maxLeft);
    			}
    			dfs(str.substr(1), remained, countLeft, maxLeft);
    		} else {
    			dfs(str.substr(1), remained + str[0], countLeft, maxLeft);
    		}
    	};

    	dfs(s, "", 0, 0);

    	if (result.empty()) result.push_back("");

		return result;
    }
};