class Solution {
private:
	// a^b mod 1337
	int pow(int a, int b) {
		a = a % 1337;  // avoid overflow!!!
		if (a == 1) return 1;
		if (b == 0) return 1;
		int half_pow = pow(a, b/2);
		int result = (half_pow * half_pow) % 1337;
		if (b & 0x1) result *= a;
		return result % 1337;
	}
	int rank(int b) {
		int ret = 10;
		while (b >= ret) {
			ret *= 10;
		}
		return ret;
	}
public:
    int superPow(int a, vector<int>& b) {
    	if (a == 1) return 1;
    	int ret = 1;
    	for (auto x: b) {
    		ret = (pow(ret, rank(x)) * pow(a, x)) % 1337;
    	}
    	return ret;       
    }
};