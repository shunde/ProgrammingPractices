class Solution {
 private:
 

 public:
  int numSquares(int n) {
  	int rootOfN = sqrt(n);
    vector<int> dp(n + 1, INT_MAX);
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
      for (int j = 1; j <= rootOfN; j++) {
      	if (i == j*j) {
      		dp[i] = 1;
      		break;
      	} else if (i > j*j) {
      		dp[i] = min(dp[i], dp[i-j*j]+1);
      	} else {
      		break;
      	}
      }
    }
    return dp[n];
  }
};