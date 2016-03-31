class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<char, char> dict;
        unordered_set<char> alphet; // no two characters map to the same character
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (dict.find(ch) != dict.end()) {
                if (dict[ch] == t[i]) continue;
                else return false;
            } else {
                if (alphet.find(t[i]) == alphet.end()) {
                    dict[ch] = t[i];
                    alphet.insert(t[i]);
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};