class Solution {
	vector<int> getNext(string pattern) {
		if (pattern.empty()) return vector<int>();
		int len = pattern.length();
		vector<int> next(len, -1);
		int i = 0, j = -1;
		while (i < len-1) {
			if (j == -1 || pattern[i] == pattern[j]) {
				i++;
				j++;
				next[i] = j;
			} else {
				j = next[j];
			}
		}
		return next;
	}
public:
    int strStr(string haystack, string needle) {
    	if (needle.empty()) return 0;
    	if (haystack.empty()) return -1;

    	vector<int> next = getNext(needle);
    	int j = 0;
    	for (int i = 0; i < haystack.length(); ) {
    		if (j == -1 || haystack[i] == needle[j]) {
    			i++;
    			j++;
    			if (j == needle.length()) 
    				return i - j;
    		} else {
    			j = next[j];
    		}
    	}
    	return -1;
    }
};