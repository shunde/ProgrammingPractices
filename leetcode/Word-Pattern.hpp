class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if (pattern.empty() && str.empty()) return true;

        int spaceCount = 0;
        for (int i = 0; i < str.length(); i++)
            if (str.at(i) == ' ') spaceCount++;
        if (pattern.size() != spaceCount+1) return false;

        istringstream ss(str);
        map<char, string> dist;
        set<string> words;

        for (int i = 0; i < pattern.size(); i++) {
            char ch = pattern.at(i);
            string word;
            ss >> word;
            if (dist.find(ch) == dist.end()) {
                
                if (words.count(word) > 0) return false;
                else words.insert(word);

                dist[ch] = word;
            } else if (dist[ch] != word) {
                return false;
            }
        }
        return true;
    }
};