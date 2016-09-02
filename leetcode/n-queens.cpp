// backtracking
class Solution {
private:
	vector<string> visualBoard(const vector<int>& board) {
		vector<string> result;
		int n = board.size();
		for (int i = 0; i < n; i++) {
			string row(n, '.');
			row[board[i]] = 'Q';
			result.push_back(row);
		}
		return result;
	}
	void solve(vector<int>& board, int row, vector<vector<string>>& result) {
		int n = board.size();
		if (row == n) {
			result.push_back(visualBoard(board));
			return;
		}
		for (int i = 0; i < n; i++) {
			board[row] = i;
			if (validBoard(board, row))
				solve(board, row+1, result);
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
    vector<vector<string>> solveNQueens(int n) {
    	vector<vector<string>> result;
    	vector<int> board(n, -1);
    	solve(board, 0, result);
    	return result;        
    }
};


// naive solution
// try all permutations
// class Solution {
// private:
// 	vector<string> visualBoard(const vector<int>& board) {
// 		vector<string> result;
// 		int n = board.size();
// 		for (int i = 0; i < n; i++) {
// 			string row(n, '.');
// 			row[board[i]] = 'Q';
// 			result.push_back(row);
// 		}
// 		return result;
// 	}
// 	bool validBoard(const vector<int>& board) {
// 		int n = board.size();
// 		for (int i = 0; i <n-1; i++) {
// 			for (int j = i+ 1; j < n; j++) {
// 				if (abs(board[i] - board[j]) == j - i)
// 					return false;
// 			}
// 		}
// 		return true;
// 	}
// public:
//     vector<vector<string>> solveNQueens(int n) {
//     	vector<vector<string>> result;
//     	vector<int> board(n);
//     	for (int i = 0; i < n; i++) {
//     		board[i] = i;
//     	}
//     	do {
//     		if (validBoard(board))
//     			result.push_back(visualBoard(board));
//     	} while (next_permutation(board.begin(), board.end()));

//     	return result;
//     }
// };