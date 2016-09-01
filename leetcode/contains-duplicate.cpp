class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    	unordered_set<int> myset;
    	for (auto x: nums) {
    		if (myset.count(x) > 0) return true;
    		myset.insert(x);
    	}
    	return false;        
    }
};