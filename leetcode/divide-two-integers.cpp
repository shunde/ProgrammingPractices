class Solution {
public:
	// O(log n)
    int divide(int dividend, int divisor) {
    	if (divisor == 0) return INT_MAX;
    	if (divisor == -1 && dividend == INT_MIN) return INT_MAX;

    	long long pDividend = abs((long long)dividend);
    	long long pDivisor = abs((long long)divisor);

    	int result = 0;

    	while (pDividend >= pDivisor) {
    		int nshift = 0;
    		while (pDividend >= (pDivisor << nshift)) {
    			nshift++;
    		}

    		result += 1 << (nshift-1);
    		pDividend -= pDivisor << (nshift-1);
    	}

    	if ((dividend > 0 && divisor > 0) ||(dividend < 0 && divisor < 0))
    		return result;
    	else
    		return -result;

    }
};