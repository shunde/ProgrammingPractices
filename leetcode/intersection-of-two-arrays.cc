class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> result;
        vector<int>::iterator ite1, ite2;
        ite1 = nums1.begin();
        ite2 = nums2.begin();
        while (ite1 != nums1.end() && ite2 != nums2.end()) {
            if (*ite1 == *ite2) {
                int num = *ite1;
                result.push_back(num);
                while (*ite1 == num) ite1++;
                while (*ite2 == num) ite2++;
            } else if (*ite1 < *ite2) {
                ite1++;
            } else {
                ite2++;
            }
        }
        return result;
    }
};