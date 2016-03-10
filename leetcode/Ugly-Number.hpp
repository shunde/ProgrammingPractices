class Solution {
public:
    bool isUgly(int num) {
    	// since 1 is the smallest ugly number.
    	if (num < 1) return false;
        while (num % 2 == 0)
        	num /= 2;
        while (num % 3 == 0)
        	num /= 3;
        while (num % 5 == 0)
        	num /= 5;

        if (num != 1) return false;
        return true;        
    }
};