class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	bool exist[256] = {false};   	
    	int longestSofar = 0;
    	for (int i = 0, j = 0; j < s.length(); j++) {
    		char c = s[j];
    		if (exist[c]) {
    			exist[c] = true;
    			int len = j - i + 1;
    			if (longestSofar < len) 
    				longestSofar = len;
    		} else {
    			while (s[i] != c) {
    				exist[s[i]] = false;
    				i++;
    			}
    			i++;
    		}    		
    	}
    	return longestSofar;        
    }
};