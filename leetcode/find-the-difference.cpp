class Solution {
public:
    char findTheDifference(string s, string t) {
        int count[26] = {0};
        for (char c: t) {
            count[c - 'a']++;
        }
        for (char c: s) {
            count[c - 'a']--;
        }
        char ret = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i]) {
                ret = 'a' + i;
                break;
            }
        }
        return ret;
    }
};