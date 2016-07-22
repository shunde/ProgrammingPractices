#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		int n = nums.size();
		if (n <= 1) return;

		// Step 1: Find median of the array, return the index of the median
		int pivot = partition(nums, 0, n - 1, (n - 1) / 2);

		// Step 2: 3-way partition
		int left = 0;
		int right = n - 1;
		int j = 0;
		while (j <= right) {
			if (nums[j] < pivot) {
				swap(nums[j], nums[left]);
				j++;
				left++;
			} else if (nums[j] > pivot) {
				swap(nums[j], nums[right]);
				right--;
			} else {
				j++;
			}
		}

		vector<int> aux(nums.begin(), nums.end());

		// Step 3: wiggle sort
		left = (n - 1) / 2;
		right = n - 1;
		for (int i = 0; i < n; i++) {
			if (i & 1 == 1) {
				nums[i] = aux[right];
				right--;
			} else {
				nums[i] = aux[left];
				left--;
			}
		}
	}
private:
	int partition(vector<int>& nums, int lo, int hi, int rank) {
		if (lo >= hi)
			return nums[lo];

		if (lo + 3 > hi) {
			// 插入排序
			for (int i = lo+1; i <= hi; i++) {
				int cur = nums[i];
				int j = i-1;
				for (; nums[j] > cur && j>=0; j--) {
					nums[j+1] = nums[j];
				}
				nums[j+1] = cur;
			}

			return nums[rank];
		}

		// nums[mid] < nums[lo] < nums[hi]
		
		int mid = (lo + hi)/2;
		if (nums[lo] > nums[mid]) swap(nums[lo], nums[mid]);
		if (nums[mid] > nums[hi]) swap(nums[mid], nums[hi]);
		if (nums[lo] < nums[mid]) swap(nums[lo], nums[mid]);

		int left = lo, right = hi;
		int pivot = nums[lo];
		while (left < right) {
			while (left < right && nums[right] >= pivot)
				right--;
			while (left < right && nums[left] <= pivot)
				left++;
			if (left < right)
				swap(nums[left], nums[right]);
		}
		swap(nums[lo], nums[right]);
		if (rank == right)
			return pivot;
		else if (rank > right)
			return partition(nums, right + 1, hi, rank);
		else
			return partition(nums, lo, right - 1, rank);
	}

};

int main() {
	vector<int> nums = {1, 3, 2, 2, 3, 1};
	Solution sol;
	sol.wiggleSort(nums);
	cout << "after wiggle sort" << endl;
	for (auto x : nums) {
		cout << x << ", ";
	}
	return 0;
}


/**
 *  sorted based solution.
 *  O(nlogn)
 */
// class Solution {
// public:
//     void wiggleSort(vector<int>& nums) {
//     	int n = nums.size();
//     	if (n < 2) return;
//     	sort(nums.begin(), nums.end());
//     	vector<int> aux(nums.begin(), nums.end());
//     	int brk = (n+1)/2 - 1;
//     	int i, j, k;
//     	i = brk;
//     	j = n-1;
//     	k = 0;
//     	while (i >= 0 && j > brk) {
//     		nums[k++] = aux[i--];
//     		nums[k++] = aux[j--];
//     	}

//     	if (i >= 0) {
//     		nums[n-1] = aux[0];
//     	}
//     	return;
//     }
// };