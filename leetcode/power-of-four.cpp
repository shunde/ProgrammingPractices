class Solution {
public:
	// 0101 0101 0101 0101 0101 0101 0101 0101 = 0x55
	// lowerbit -> (x & -x) 提取最低位
    bool isPowerOfFour(int num) {
        int mask = 0x55555555;
        if ((num & -num) != num) return false;
        
        if (num & mask) return true;
        return false;
        
    }
};