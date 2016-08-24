class Solution {
public:
    int firstUniqChar(string s) {
    	// You may assume the string contain only lowercase letters.
    	int count[26] = {0};
    	int ret = -1;
    	for (int i = 0; i < s.length(); i++) {
    		count[s[i]-'a']++;
    	}
    	for (int i = 0; i < s.length(); i++) {
    		if (count[s[i]-'a'] == 1) return i;
    	}
        return -1;
    }
};