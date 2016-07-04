class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
    	size_t n = nums.size();
    	if (n == 0) return vector<int>();

    	vector<int> counts(n, 0);

    	vector<int> sortedList;    	
    	sortedList.reserve(n);
    	

    	for (int i = n - 1; i >= 0; i--) {
    		auto pos = lower_bound(sortedList.begin(), sortedList.end(), nums[i]);
    		counts[i] = distance(sortedList.begin(), pos);
    		sortedList.insert(pos, nums[i]);
    	}
    	return counts;
    }
};