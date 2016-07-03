class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 1) return false;
        
        unsigned int upper_bound = 1;
        int exp = 0;
        while (upper_bound < num) {
            upper_bound <<= 1;
            exp++;
        }
        exp = (exp+1)/2;
        int lo, hi;
        hi = 1 << exp;
        lo = hi / 2;
        for (int i = lo; i <= hi; i++) {
            if (num == i * i) {
                return true;
            }
        }
        return false;
    }
};