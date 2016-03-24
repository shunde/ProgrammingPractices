class Solution {
public:
    int countDigitOne(int n) {
        if (n < 1) return 0;
        int iCount = 0;
        long long factor = 1;       // consider factor overflow, so use long long     
        int iLowerNum = 0;
        int iCurrentNum = 0;
        int iHigherNum = 0;
        while (n > factor) {
            iLowerNum = n - (n / factor) * factor;
            iCurrentNum = (n / factor) % 10;
            iHigherNum = n / (factor * 10);

            switch (iCurrentNum) {
            case 0:
                iCount += iHigherNum * factor;
                break;
            case 1:
                iCount += iHigherNum * factor + iLowerNum + 1;
                break;
            default:
                iCount += (iHigherNum + 1) * factor;
                break;
            }
            factor *= 10;     // beware of overflow.
        }
        return iCount;
    }
};