class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> mystack;
        for (int i = 0; i < num.length();) {
            if (k > 0 && !mystack.empty() && mystack.back() > num[i]) {
                mystack.pop_back();
                k--;
            } else {
                mystack.push_back(num[i]);
                i++;
            }
           
        }
        
        while (k > 0 && !mystack.empty()) {
            mystack.pop_back();
            k--;
        }
        auto it = mystack.begin();
        while (it != mystack.end() && *it == '0') it++;
        string ans(it, mystack.end());
        
        if (ans.empty()) return "0";
        return ans;
        
    }
};