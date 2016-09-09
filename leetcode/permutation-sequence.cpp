class Solution {
public:
    string getPermutation(int n, int k) {
    	string result;
    	vector<char> candidates;
    	for (int i = 0; i < n; i++) {
    		candidates.push_back('1' + i);
    	}

    	k = k-1;  // convert to 0-based index
    	int fact = 1;
    	for (int i = 1; i <= n-1; i++) {
    		fact *= i;
    	}

    	for (int i = 1; i < n; i++) {
    		int idx = k / fact;
    		result += candidates[idx];
    		candidates.erase(candidates.begin()+idx);
    		k %= fact;
    		fact /= (n-i);
    	}

    	result += candidates[0];

    	return result;
        
    }
};