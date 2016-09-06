class Solution {
 public:
  int mySqrt(int x) {
    int exp = 1;
    long long upper_bound = 2;
    while (x > upper_bound) {
      exp++;
      upper_bound <<= 1;
    }
    int lo = 0x01 << ((exp - 1) / 2);
    int hi = 0x01 << ((exp + 1) / 2);

    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      // mid -> long long, avoid overflow
      long long power = (long long)mid * mid;
      if (power > x)
        hi = mid - 1;
      else if (power < x)
        lo = mid + 1;
      else
        return mid;
    }
    return hi;
  }
};