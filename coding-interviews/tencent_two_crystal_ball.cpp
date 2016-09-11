/**
 * 腾讯大厦有39层，有两颗玻璃球，坚硬成都相同。
 * 存在某个临界楼层，从此楼层以下的任一楼层扔下，不会碎；
 * 从此楼层及以上楼层扔下，会碎。
 * 问，最少扔多少次，可以求出此临界楼层
 * f(39) = 9;
 * f(100) = 14;
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int f(int n) {
    vector<int> dp(n+1, INT_MAX);
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            dp[i] = min(dp[i], 1+ max(j-1, dp[i-j]));
        }
    }

    return dp[n];
};

int main() {
    int n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}
