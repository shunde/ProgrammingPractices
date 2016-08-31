/**
 * 变位词问题，参见《编程珠玑》。
 */
class Solution {
	string getToken(string word) {
		sort(word.begin(), word.end());
		return word;
	}
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    	vector<vector<string>> result;
    	unordered_map<string, vector<string>> anagramList;
    	for (auto& w: strs) {
    		string token = getToken(w);
    		anagramList[token].push_back(w);    		
    	}

    	for (auto it = anagramList.begin(); it != anagramList.end(); it++) {
    		result.push_back(it->second);
    	}
    	return result;
    }
};