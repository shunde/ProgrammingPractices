class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    	int longest_sofar = 0;
    	unordered_set<int> myset;
    	for (auto x: nums)
    		myset.insert(x);

    	for (auto x: myset) {
    		int left = x - 1;
    		int right = x + 1;
    		int count = 1;

    		while (myset.find(left) != myset.end()) {
    			count++;
    			myset.erase(left);
    			left--;
    		}
    		while (myset.find(right) != myset.end()) {
    			count++;
    			myset.erase(right);
    			right++;
    		}
    		if (longest_sofar < count) 
    			longest_sofar = count;
    	}
    	return longest_sofar;
        
    }
};