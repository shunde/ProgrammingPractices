class Solution {
public:
    string toHex(int num) {
        char* codec = "0123456789abcdef";
        unsigned int unum = num;
        unsigned int mask = 0x0f;
        string ans;
        while (unum > 0) {
            ans = codec[unum & mask] + ans;
            unum >>= 4;
        }
        if (ans.empty()) ans = "0";
        return ans;
    }
};