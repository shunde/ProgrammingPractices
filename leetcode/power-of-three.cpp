class Solution {
public:
	// math equation
	// $log_b(x) = \frac{log_{10}(x)}{log_{10}(b)} = \frac{log_e(x)}{log_e(b)}$
	bool isPowerOfThree(int n) {
		if (n < 1) return false;

		int exp = (int)round(log(n) / log(3));

		if ((int)pow(3, exp) == n) return true;
		else return false;

	}
};