class Solution {
private:
	string normalize(string p) {
		if (p.length() < 2) return p;
		string ret;
		ret += p[0];
		for (int i = 1; i < p.length(); i++) {
			if (p[i] == '*' && p[i-1] == '*')
				continue;
			ret += p[i];
		}
		return ret;
	}
public:
    bool isMatch(string s, string p) {
    	p = normalize(p);
    	if (!p.empty() && p.back() != '*') {
    		if (!s.empty()) {
    			if (p.back() == '?' || p.back() == s.back())
    				return isMatch(s.substr(0, s.length() - 1), p.substr(0, p.length() - 1));
    			else 
    				return false;
    		}
    		return false;
    	}
       	int i = 0, j = 0;
    	for (; i < s.length() && j < p.length(); ) {
    		if (p[j] == '?') {
    			i++;
    			j++;
    		} else if (p[j] == '*') {
    			for (int k = i; k <= s.length(); k++) {
    				if (isMatch(s.substr(k), p.substr(j+1)))
    					return true;
    			}
    			return false;
    		} else {
    			if (s[i] != p[j]) return false;
    			i++;
    			j++;
    		}
    	}

    	if (i < s.length()) return false;
    	while (j < p.length() && p[j] == '*') j++;
    	if (j < p.length()) return false;
    	return true;
    }
};