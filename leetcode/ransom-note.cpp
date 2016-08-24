class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
    	int count[256] = {0};
    	for (char c: magazine) {
    		count[c]++;
    	}
    	for (char c: ransomNote) {
    		count[c]--;
    		if (count[c] < 0) return false;
    	}
    	return true;        
    }
};