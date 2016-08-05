class Solution {
public:
    int longestValidParentheses(string s) {
    	int len = s.length();
    	if (len < 2) return 0;
    	stack<int> leftIdx;
        int lastValidLen = 0;
        int curValidLen = 0;
        int maxLenSofar = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == '(') leftIdx.push(i);
            else {
                if (leftIdx.empty()) {
                    lastValidLen = 0;
                } else {
                    int idx = leftIdx.top();
                    leftIdx.pop();

                    if (leftIdx.empty()) {
                        curValidLen = i - idx + 1;
                        lastValidLen += curValidLen;
                        maxLenSofar = max(maxLenSofar, lastValidLen);
                    } else {
                        curValidLen = i - leftIdx.top();
                        maxLenSofar = max(maxLenSofar, curValidLen);
                    }                                         
                }
            }
        }  
        
        return maxLenSofar;
    }
};