/**
 * reference: http://www.programcreek.com/2014/06/leetcode-wildcard-matching-java/
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int startIndex = -1;
        int iIndex = -1;
        while (i < s.length()) {
            if (j < p.length() && (p[j] == '?' || s[i] == p[j])) {
                i++;
                j++;
            } else if (j < p.length() && p[j] == '*') {
                startIndex = j;
                iIndex = i;
                j++;
            } else if (startIndex != -1) {
                j = startIndex + 1;
                i = iIndex + 1;
                iIndex++;
            } else {
                return false;
            }
        }
        while (j < p.length() && p[j] == '*') j++;
        return j == p.length();
    }
};