class Solution {
public:
    int numTrees(int n) {
    	vector<int> count(n+1, 0);
    	count[0] = 1;
    	count[1] = 1;
    	for (int i = 2; i <= n; i++) {
    		for (int k = 1; k <= i; k++) {
    			count[i] += count[k-1]*count[i-k];
    		}
    	}
    	return count[n];
    }
};