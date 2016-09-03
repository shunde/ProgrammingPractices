// dfs with memorization
class Solution {
	int getLongestIncreasingPath(vector<vector<int>>& dp, vector<vector<int>>& matrix, int i, int j, int prev) {
		int rows = matrix.size();
    	int cols = matrix[0].size();
    	if (i < 0 || i >= rows || j < 0 || j >= cols || matrix[i][j] <= prev) return 0;
    	if (dp[i][j] == 0) {
    		dp[i][j] = max(dp[i][j], 1 + getLongestIncreasingPath(dp, matrix, i-1, j, matrix[i][j]));
    		dp[i][j] = max(dp[i][j], 1 + getLongestIncreasingPath(dp, matrix, i+1, j, matrix[i][j]));
    		dp[i][j] = max(dp[i][j], 1 + getLongestIncreasingPath(dp, matrix, i, j-1, matrix[i][j]));
    		dp[i][j] = max(dp[i][j], 1 + getLongestIncreasingPath(dp, matrix, i, j+1, matrix[i][j]));
    	}
    	return dp[i][j];
	}
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
    	if (matrix.empty() || matrix[0].empty()) return 0;
    	int rows = matrix.size();
    	int cols = matrix[0].size();
    	// dp[i][j] 以(i,j)为起点的最长增长路径
    	vector<vector<int>> dp(rows, vector<int>(cols, 0)); 
    	int result = 0;

    	for (int i = 0; i < rows; i++) {
    		for (int j = 0; j < cols; j++) {
    			result = max(result, getLongestIncreasingPath(dp, matrix, i, j, INT_MIN));
    		}
    	}
    	return result;       
    }
};

// dfs: Time Limit Exceeded
// class Solution {
// 	void dfs(vector<vector<int>>& matrix, int i, int j, int prev, int len, int& longestSofar) {
// 		int rows = matrix.size();
// 		int cols = matrix[0].size();
// 		if (i < 0 || i >= rows || j < 0 || j >= cols || matrix[i][j] <= prev) {
// 			longestSofar = max(len, longestSofar);
// 			return;
// 		}
// 		len++;
// 		prev = matrix[i][j];

// 		dfs(matrix, i-1, j, prev, len, longestSofar);
// 		dfs(matrix, i+1, j, prev, len, longestSofar);
// 		dfs(matrix, i, j-1, prev, len, longestSofar);
// 		dfs(matrix, i, j+1, prev, len, longestSofar);
// 	}
// public:
//     int longestIncreasingPath(vector<vector<int>>& matrix) {
//     	int result = 0;
//     	if (matrix.empty() || matrix[0].empty()) return result;

//     	int rows = matrix.size();
//     	int cols = matrix[0].size();

//     	for (int i = 0; i < rows; i++) {
//     		for (int j = 0; j < cols; j++) {
//     			dfs(matrix, i, j, INT_MIN, 0, result);
//     		}
//     	}

//     	return result;
//     }
// };