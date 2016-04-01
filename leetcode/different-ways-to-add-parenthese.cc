class Solution {
    void plus(vector<int> &left, vector<int> &right, vector<int> &result) {
        for (int i = 0; i < left.size(); i++)
            for (int j = 0; j < right.size(); j++) {
                result.push_back(left[i]+right[j]);
            }
    }

    void minus(vector<int> &left, vector<int> &right, vector<int> &result) {
        for (int i = 0; i < left.size(); i++)
            for (int j = 0; j < right.size(); j++) {
                result.push_back(left[i]-right[j]);
            }
    }

    void multiply(vector<int> &left, vector<int> &right, vector<int> &result) {
        for (int i = 0; i < left.size(); i++)
            for (int j = 0; j < right.size(); j++) {
                result.push_back(left[i]*right[j]);
            }
    }
    
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        size_t start = 0, nextOps;
        nextOps = input.find_first_of("+-*", start);
        if (nextOps == string::npos) {
            int val = stoi(input);
            result.push_back(val);
            return result;
        }
        while (nextOps != string::npos) {
            vector<int> leftResult;
            vector<int> rightResult;

            leftResult = diffWaysToCompute(input.substr(0, nextOps-0));
            rightResult = diffWaysToCompute(input.substr(nextOps+1));

            char op = input[nextOps];
            if (op == '+')
                plus(leftResult, rightResult, result);
            else if (op == '-')
                minus(leftResult, rightResult, result);
            else if (op == '*')
                multiply(leftResult, rightResult, result);
            else {
                // won't happen
            }

            nextOps = input.find_first_of("+-*", nextOps+1);
        }

        return result;       
    }
};