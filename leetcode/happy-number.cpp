class Solution {
private:
	int getNum(int n) {
		int result = 0;
		while (n) {
			result += (n%10)*(n%10);
			n /= 10;
		}
		return result;
	}
public:
    bool isHappy(int n) {
    	// 纪录出现的中间数字，如果重复出现，则表示存在循环
    	unordered_set<int> myset;

    	while (myset.find(n) == myset.end()) {
    		myset.insert(n);

    		n = getNum(n);

    		if (n == 1) return true;
    	}

    	return false;
        
    }
};