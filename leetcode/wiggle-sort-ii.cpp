class Solution {
public:
    void wiggleSort(vector<int>& nums) {
    	int n = nums.size();
    	if (n < 2) return;
    	sort(nums.begin(), nums.end());
    	vector<int> aux(nums.begin(), nums.end());
    	int brk = (n+1)/2 - 1;
    	int i, j, k;
    	i = brk;
    	j = n-1;
    	k = 0;
    	while (i >= 0 && j > brk) {
    		nums[k++] = aux[i--];
    		nums[k++] = aux[j--];
    	}

    	if (i >= 0) {
    		nums[n-1] = aux[0];
    	}
    	return;
    }
};