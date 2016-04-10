class Solution {
    int findKth(int A[], int lenA, int B[], int lenB, int k) {
        if (lenA == 0) return B[k];
        if (lenB == 0) return A[k];
        if (k == 0) return min(A[0], B[0]);

        int midA = lenA * k / (lenA + lenB);
        int midB = k - midA - 1;

        if (A[midA] > B[midB]) {
            k = k - midB - 1;
            return findKth(A, midA + 1, B + midB + 1, lenB - midB - 1, k);
        } else {
            k = k - midA - 1;
            return findKth(A + midA + 1, lenA - midA - 1, B, midB + 1, k);
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        if ((m + n) % 2 != 0) {
            return findKth(nums1.data(), n, nums2.data(), m, (n + m) / 2);
        } else {
            return (findKth(nums1.data(), n, nums2.data(), m, (n + m) / 2) +
                    findKth(nums1.data(), n, nums2.data(), m, (n + m) / 2 - 1)) * 0.5;
        }
    }
};