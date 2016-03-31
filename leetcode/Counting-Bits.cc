class Solution {
private:
    bool isPowerOf2(int x) {
        return x && !(x & (x-1));
    }
public:
    vector<int> countBits(int num) {
        vector<int> bit1Count(num+1, 0);
        int lastPower2;
        for (int i = 1; i <= num; i++) {
            if (isPowerOf2(i)) {
                bit1Count[i] = 1;
                lastPower2 = i;
            } else {
                bit1Count[i] = bit1Count[i-lastPower2] + 1;
            }
        }
        return bit1Count;        
    }
};