/**
 * refer to http://www.programcreek.com/2014/06/leetcode-substring-with-concatenation-of-all-words-java/
 */
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
    	vector<int> result;
        if (s.empty() || words.empty() || s.length() < words[0].length()) return result;

        unordered_map<string, int> mymap;
        for (auto& w: words) {
        	if (mymap.find(w) != mymap.end()) {
        		mymap[w]++;
        	} else {
        		mymap[w] = 1;
        	}
        }
        int len = words[0].length(); 
        // *Attention: j < len       
        for (int j = 0; j < len; j++) {
        	int start = j;
        	int count = 0;
        	unordered_map<string, int> currmap;
        	for (int i = j; i <= s.length() - len; i+=len) {
        		string word = s.substr(i, len);
        		if (mymap.find(word) != mymap.end()) {
        			currmap[word]++;
        			count++;
        			while (currmap[word] > mymap[word]) {
        				string w = s.substr(start, len);
        				start += len;
        				currmap[w]--;
        				count--;
        				if (currmap[w] <= 0) 
        					currmap.erase(w);
        			}

        			if (count == words.size()) {
        				result.push_back(start);
        				string w = s.substr(start, len);
        				start += len;
        				count--;
        				currmap[w]--;
        				if (currmap[w] <= 0) 
        					currmap.erase(w);
        			}
        		} else {
        			currmap.clear();
        			count = 0;
        			start = i + len;
        		}
        	}
        }
        return result;
    }
};