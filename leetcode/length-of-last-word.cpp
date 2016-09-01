class Solution {
public:
    int lengthOfLastWord(string s) {
    	int len = s.length();
    	int i, j;
    	j = len - 1;
    	while (j >= 0 && !isalpha(s[j])) j--;
    	i = j-1;
    	while (i >= 0 && isalpha(s[i])) i--;

    	if (j >= 0) return j - i;
    	else return 0;
    }
};