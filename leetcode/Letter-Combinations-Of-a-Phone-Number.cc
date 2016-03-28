class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty() || digits.find_first_of("01") != string::npos) 
            return vector<string> ();

        string letters[10] = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
        vector<string> result;
        int n = digits.size();
        vector<int> trace(n, 0);

        while (true) {
            string word(n, '*');
            for (int i = 0; i < n; i++) {
                word[i] = letters[digits[i]-'0'][trace[i]];
            }
            result.push_back(word);
            int k = n-1;
            while (k >= 0) {
                if (trace[k] < (letters[digits[k]-'0']).length()-1) {
                    trace[k]++;
                    break;
                } else {
                    trace[k] = 0;
                    k--;
                }
            }
            if (k < 0)
                break;
        }
        return result;        
    }
};