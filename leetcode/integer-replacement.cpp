class Solution {
 public:
  int integerReplacement(int n) {
    int cnt = 0;
    int64_t N = n;
    while (N != 1) {
      if (N % 2 == 0) {
        N = N >> 1;
      } else {
        if (N == 3) {
          cnt += 2;
          break;
        }

        N = (N & 2) == 2 ? N + 1 : N - 1;
      }
      cnt++;
    }
    return cnt;
  }
};