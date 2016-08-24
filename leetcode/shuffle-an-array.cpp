class Solution {
public:
    Solution(vector<int> nums) {
    	original = nums;
    	srand(time(NULL));        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
    	vector<int> perm(original.begin(), original.end());
    	for (int i = 1; i < perm.size(); ++i) {
    		int idx = rand() % (i+1);
    		swap(perm[i], perm[idx]);
    	}
    	return perm;        
    }
private:
	vector<int> original;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */