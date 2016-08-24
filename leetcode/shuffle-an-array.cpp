class Solution {
public:
    Solution(vector<int> nums) {
    	original = nums;        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
    	vector<int> perm(original.begin(), original.end());
    	for (int i = 1; i < perm.size(); ++i) {
    		
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