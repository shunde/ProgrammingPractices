class Solution {
private:
    int gcd(int a, int b) {
        if (b == 0) return a;
        else return gcd(b, a%b);
    }
    
public:
    bool canMeasureWater(int x, int y, int z) {
        if (z == 0 || (x == z && y == 0) || (x == 0 && y == z)) return true;
        if (x == 0 || y == 0 || x+y < z) return false;
        if (z % gcd(x, y) == 0) return true;
        return false;
    }
};