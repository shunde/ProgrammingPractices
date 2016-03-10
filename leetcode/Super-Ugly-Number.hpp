class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
       int *uglyNums = new int[n];
       int k = primes.size(); 
       int *multiply = new int[k]();

       uglyNums[0] = 1;
       for (int i = 1; i < n; i++) {
           int nextUgly = uglyNums[multiply[0]] * primes[0];
           for (int j = 1; j < k; j++) {
           	   nextUgly = min(nextUgly, uglyNums[multiply[j]] * primes[j]);
           }

           // update multiply index.
           for (int j = 0; j < k; j++) {
           	   while (multiply[j] < i && uglyNums[multiply[j]] * primes[j] <= nextUgly)
           	   	    multiply[j]++;
           }
           uglyNums[i] = nextUgly;
       }
       int ret = uglyNums[n-1];
       delete uglyNums;
       delete multiply;
       return ret;
    }
};