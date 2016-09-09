// dp
// refer to http://www.geeksforgeeks.org/check-whether-a-given-string-is-an-interleaving-of-two-other-given-strings-set-2/
class Solution {
 public:
  bool isInterleave(string s1, string s2, string s3) {
    int len1 = s1.length();
    int len2 = s2.length();
    int len3 = s3.length();

    if (len3 != len1 + len2) return false;

    // dp[i][j] will be true if s3[0..i+j-1]
    // is an interleaving of s1[0..i-1] and s2[0..j-1].
    vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));

    for (int i = 0; i <= len1; i++) {
      for (int j = 0; j <= len2; j++) {
        // two empty strings have an empty interleaving
        if (i == 0 && j == 0) {
          dp[i][j] = true;
        } else if (i == 0) {
          if (s2[j - 1] == s3[j - 1]) dp[i][j] = dp[i][j - 1];
        } else if (j == 0) {
          if (s1[i - 1] == s3[i - 1]) dp[i][j] = dp[i - 1][j];
        } else if (s1[i - 1] == s3[i + j - 1] && s2[j - 1] != s3[i + j - 1]) {
          dp[i][j] = dp[i - 1][j];
        } else if (s1[i - 1] != s3[i + j - 1] && s2[j - 1] == s3[i + j - 1]) {
          dp[i][j] = dp[i][j - 1];
        } else if (s1[i - 1] == s3[i + j - 1] && s2[j - 1] == s3[i + j - 1]) {
          dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]);
        }
      }
    }
    return dp[len1][len2];
  }
};