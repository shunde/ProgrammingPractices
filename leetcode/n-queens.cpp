// naive solution
// try all permutations
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
	bool validBoard(const vector<int>& board) {
		int n = board.size();
		for (int i = 0; i <n-1; i++) {
			for (int j = i+ 1; j < n; j++) {
				if (abs(board[i] - board[j]) == j - i)
					return false;
			}
		}
		return true;
	}
public:
    vector<vector<string>> solveNQueens(int n) {
    	vector<vector<string>> result;
    	vector<int> board(n);
    	for (int i = 0; i < n; i++) {
    		board[i] = i;
    	}
    	do {
    		if (validBoard(board))
    			result.push_back(visualBoard(board));
    	} while (next_permutation(board.begin(), board.end()));

    	return result;
    }
};