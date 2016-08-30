class Solution {
public:
    bool isMatch(string s, string p) {
    	if (p.empty()) return s.empty();

    	// len(p) = 1
    	if (p.length() == 1) {
    		if (s.length() != 1) return false;
    		else if (s[0] != p[0] && p[0] != '.') return false;
    		else return true;
    	} 

    	// second char of p is not '*'
    	if (p[1] != '*') {
    		if (s.length() < 1 || (s[0] != p[0] && p[0] != '.')) return false;
    		return isMatch(s.substr(1), p.substr(1));
    	}  // second char of p is '*'
    	else {
    		// "x*" -> zero element
    		if (isMatch(s, p.substr(2))) return true;

    		int i = 0;
    		while (i < s.length() && (s[i] == p[0] || p[0] == '.')) {
    			if (isMatch(s.substr(i+1), p.substr(2))) return true;
    			i++;
    		}
    		return false;
    	}       
    }
};