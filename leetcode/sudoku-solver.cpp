class Solution {
private:
	bool solve(vector<vector<char>>& board) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.') continue;

				for (int k = 0; k < 9; k++) {
					board[i][j] = k + '1';
					if (validSudoku(board, i, j) && solve(board)) return true;
					board[i][j] = '.';
				}
				return false;
			}
		}
		return true;  // does not matter
	}
	bool validSudoku(const vector<vector<char>>& board, int i, int j) {
		// valid row
		{
			vector<bool> exist(9, false);
			for (int k = 0; k < 9; k++) {				
				if (board[i][k] != '.') {
					int idx = board[i][k] - '1';
					if (exist[idx]) return false;
					exist[idx] = true;
				}
			}
		}

		// valid col
		{
			vector<bool> exist(9, false);
			for (int k = 0; k < 9; k++) {				
				if (board[k][j] != '.') {
					int idx = board[k][j] - '1';
					if (exist[idx]) return false;
					exist[idx] = true;
				}
			}
		}

		// valid matrix
		{
			vector<bool> exist(9, false);
			for (int m = 0; m < 3; m++) {
				for (int n = 0; n < 3; n++) {
					int x = (i/3)*3 + m;
					int y = (j/3)*3 + n;
					if (board[x][y] != '.') {
						int idx = board[x][y] - '1';
						if (exist[idx]) return false;
						exist[idx] = true;
					}
				}
			}
		}
		return true;
	}
public:
	void solveSudoku(vector<vector<char>>& board) {
		solve(board);
	}
};