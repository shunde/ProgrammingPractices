class Solution {
public:
    string minWindow(string s, string t) {
    	
    	string result;
    	if (s.empty() || s.length() < t.length()) return "";

    	vector<int> alphabets(256, 0);
    	vector<int> currAlphabets(256, 0);
    	
    	int count = 0;
    	int minLenSofar = INT_MAX;
    	for (auto c: t) {
    		alphabets[c]++;
    	}
    	

    	for ( int i = 0,j = 0; i <= j && j < s.length(); j++) {
    		char c = s[j];
    		if (alphabets[c] > 0) {

    			currAlphabets[c]++;

    			if (currAlphabets[c] <= alphabets[c])
    				count++;

    			// Note: this condition is very important.
    			while (count == t.length()) {
    				
    				int len = j - i + 1;
    				if (len < minLenSofar) {
    					result = s.substr(i, len);
    					minLenSofar = len;
    				}
    				currAlphabets[s[i]]--;
    				if (currAlphabets[s[i]] < alphabets[s[i]])
    					count--;
    				i++;
    				while (!alphabets[s[i]]) i++;
    			}

    		} else if(count == 0){
    			i = j+1;
    		}
    	}

    	return result;
    }
};