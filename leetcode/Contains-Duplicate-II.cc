class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> dist;
        unordered_map<int, int>::iterator iter;
        for (int i = 0; i < nums.size(); i++) {
        	iter = dist.find(nums[i]);
        	if (iter != dist.end()) {
        		if (i - iter->second <= k)
        			return true;
        		else
        			iter->second = i;
        	} else {
        		dist.insert(make_pair(nums[i], i));
        	}    
        }
        return false;
    }
};