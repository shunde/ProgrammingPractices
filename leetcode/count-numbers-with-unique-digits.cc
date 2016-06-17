class Solution {

public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n == 1) return 10;
        if (n > 10) return countNumbersWithUniqueDigits(10);
        int A9[] = {9, 72, 504, 3024, 15120, 60480, 181440, 362880, 362880};
        return 9*A9[n-2] + countNumbersWithUniqueDigits(n-1); 
    }
};