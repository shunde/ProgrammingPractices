class Solution {
public:
    string multiply(string num1, string num2) {
        std::reverse(num1.begin(), num1.end());
        std::reverse(num2.begin(), num2.end());
        int carry = 0;
        int curr = 0;
        int num1_digits = num1.size();
        int num2_digits = num2.size();
        int max_digits = num1_digits + num2_digits;
        vector<int> results(max_digits, 0);
        for (int i = 0; i < num1_digits; i++) {
            for (int j = 0; j < num2_digits; j++) {
                int val = (num1[i] - '0') * (num2[j] - '0');
                results[i+j] += val;
            }
        }
        for (int i = 0; i < max_digits - 1; i++) {
            if (results[i] >= 10) {
                results[i+1] += results[i] / 10;
                results[i] = results[i] % 10;
            }
        }
        string ret;
        ret.reserve(max_digits);
        int idx = max_digits - 1;
        while (idx >= 0 && results[idx] == 0) {
            idx--;
        }
        for (; idx >= 0; idx--) {
            ret += results[idx] + '0';
        }
        if (ret.empty()) ret = "0";
        return ret;
    }
};