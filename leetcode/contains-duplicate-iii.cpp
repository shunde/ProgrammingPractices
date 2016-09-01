/**
 * tree-based set
 * lower_bound && upper_bound
 * refer to http://www.programcreek.com/2014/06/leetcode-contains-duplicate-iii-java/
 */
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    	if(nums.size() < 2 || k < 1 || t < 0) return false;
    	set<long long> myset;
    	for (int i = 0; i < nums.size(); i++) {
    		long long leftBound = (long long)nums[i] - t;
    		long long rightBound = (long long)nums[i] + t;
    		auto itlow = myset.lower_bound(leftBound);
    		auto itup = myset.upper_bound(rightBound);

    		set<long long> subset(itlow, itup);
    		if (!subset.empty()) return true;
    		
    		myset.insert(nums[i]);
    		
    		if (i>=k) {
    			myset.erase(nums[i-k]);
    		}
    		
    	} 
    	return false;       
    }
};