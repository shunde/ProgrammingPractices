// backtracking
class Solution {
private:
	void solve(vector<int>& board, int row, int& cnt) {
		int n = board.size();
		if (row == n) {
			cnt++;
			return;
		}
		for (int i = 0; i < n; i++) {
			board[row] = i;
			if (validBoard(board, row))
				solve(board, row+1, cnt);
		}
	}
	bool validBoard(const vector<int>& board, int row) {
		for (int i = 0; i < row; i++) {
			// skip uninitialized row
			if (board[i] == -1) continue;
			if (board[i] == board[row]) return false;
			if (abs(board[row] - board[i]) == row - i)
				return false;
		}
		return true;
	}
public:
    int totalNQueens(int n) {
    	int cnt = 0;
    	vector<int> board(n, -1);
    	solve(board, 0, cnt);
    	return cnt;        
    }
};