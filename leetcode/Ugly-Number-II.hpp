/**
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
 * 
 */

class Solution {
public:
    int nthUglyNumber(int n) {
    	int *uglyNums = new int[n];
    	uglyNums[0] = 1;

    	int *multiply2 = uglyNums;
    	int *multiply3 = uglyNums;
    	int *multiply5 = uglyNums;

    	for (int i = 1; i < n; i++) {
    		int nextUgly = min(min(*multiply2 * 2, *multiply3 * 3), *multiply5 * 5);
    		uglyNums[i] = nextUgly;
    		
    		if (nextUgly == *multiply2 * 2)
    			multiply2++;

    		if (nextUgly == *multiply3 * 3)
    			multiply3++;

    		if (nextUgly == *multiply5 * 5)
    			multiply5++;
    		
    	}   
    	int ret = uglyNums[n-1];
    	delete uglyNums;
    	return ret;
    }
};