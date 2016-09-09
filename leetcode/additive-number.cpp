// 思路：
// 只要前面两个数确定了，后面的序列也就确定了。
// 只用枚举前两个数的可能状态。

class Solution {
    // 从 num[i, j),  num[j, k) 状态出发，看能否走到尽头
    bool dfs(const string& num, int i, int j, int k) {
        long long num1 = stoll(num.substr(i, j-i));
        long long num2 = stoll(num.substr(j, k-j));
        string sum = std::to_string(num1 + num2);

        if (num.compare(k, sum.length(), sum) == 0) {
            if (num.substr(k).length() == sum.length()) return true;
            return dfs(num, j, k, k+sum.length());
        }
        return false;
    }
 public:
  bool isAdditiveNumber(string num) {
    // should contain at least three numbers
    if (num.length() < 3) return false;

    for (int i = 1; i <= num.length() / 2; i++) {
        if (num[0] == '0' && i > 1) break;
        for (int j = i+1; j < num.length(); j++) {
            if (num[i] == '0' && j - i > 1) break;
            if (dfs(num, 0, i, j)) return true;
        }
    }
    return false;

  }
};
