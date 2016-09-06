/**
 * 所谓幸运数字就是每一位的数字除了4就是7，例如4,7,44,47,74,77,444,447,474,477,744,747,774,777....。
 * 第K个幸运数字就是，就是所有幸运数字从大到小排列，第1个为4，第2个为7，第3个为44，第4个为47，第5个为74.......
 * 输入第一行为求幸运数字的个数T（1≤T≤1000），之后每行是要求的第K个幸运数字（1≤K≤10^18）
 * 例如：
 * 本地输入：
 * 3
 * 5
 * 100
 * 1000000000
 * 输出：
 * 74
 * 744747
 * 77477744774747744747444444447
 **/

#include <iostream>
#include <vector>
using namespace std;

void printKthLuckyNumber(long long k) {
  int bits = 1;
  long long upper_bound = 2;
  while (k > upper_bound) {
    bits++;
    k -= upper_bound;
    upper_bound <<= 1;
  }
  k -= 1;
  string result(bits, '4');
  for (int i = 0; i < bits; i++) {
    if (k & (0x1 << i)) {
      result[bits - 1 - i] = '7';
    }
  }
  cout << result << endl;
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    long long k;
    cin >> k;
    printKthLuckyNumber(k);
  }
  return 0;
}
