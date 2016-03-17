class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n;
        vector<string> result;        
        if ((n = nums.size()) == 0) return result;
        int start, end;
        start = end = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] == end + 1) {
                end++;
            } else {
                string str;
                if (start == end) {
                    str = to_string(start);
                } else {
                    str = to_string(start) + "->" + to_string(end);
                }
                result.push_back(str);

                start = end = nums[i];
            }
        }

        string str;
        if (start == end) {
            str = to_string(start);
        } else {
            str = to_string(start) + "->" + to_string(end);
        }
        result.push_back(str);         
    }
};