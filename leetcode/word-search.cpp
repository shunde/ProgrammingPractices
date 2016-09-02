class Solution {
private:
	bool dfs(vector<vector<char>>& board, int i, int j, const string &word, int k) {
		int row = board.size();
		int col = board[0].size();
		if (i < 0 || i >= row || j < 0 || j >= col) return false;
		if (board[i][j] != word[k]) return false;
		else if (k == word.length() - 1 ) {
			return true;
		} else {
			char origin = board[i][j];
			board[i][j] = '#'; // marked as visited
			if (dfs(board, i - 1, j, word, k + 1)
			        || dfs(board, i + 1, j, word, k + 1)
			        || dfs(board, i, j - 1, word, k + 1)
			        || dfs(board, i, j + 1, word, k + 1)
			   )
				return true;

			board[i][j] = origin;
			return false;
		}
	}
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (board.empty() || board[0].empty() || word.empty()) return false;
		int row = board.size();
		int col = board[0].size();
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (dfs(board, i, j, word, 0)) return true;
			}
		}
		return false;
	}
};

// Accepted solution
// class Solution {
// private:
// 	struct pair_hash {
// 		inline std::size_t operator()(const std::pair<int,int> &v) const {
// 			return v.first * 31 + v.second;
// 		}
// 	};
// 	unordered_set<pair<int, int>, pair_hash> visited;
// private:
// 	bool existAux(vector<vector<char>>& board, int i, int j, string word) {
// 		if (word.empty()) return true;
// 		int row = board.size();
// 		int col = board[0].size();
// 		if (i < 0 || i >= row || j < 0 || j >= col) return false;
// 		if (board[i][j] != word[0] || visited.find(make_pair(i,j)) != visited.end()) return false;
// 		visited.insert(make_pair(i,j));
// 		int step[][2] = {{ -1, 0}, {1, 0}, {0, -1}, {0, 1}};
// 		for (int k = 0; k < 4; k++) {
// 			int x = i + step[k][0];
// 			int y = j + step[k][1];
// 			if (existAux(board, x, y, word.substr(1))) return true;
// 		}
// 		visited.erase(make_pair(i,j));
// 		return false;
// 	}
// public:
// 	bool exist(vector<vector<char>>& board, string word) {
// 		if (board.empty() || board[0].empty() || word.empty()) return false;
// 		visited.clear();
// 		int row = board.size();
// 		int col = board[0].size();
// 		for (int i = 0; i < row; i++) {
// 			for (int j = 0; j < col; j++) {
// 				if (existAux(board, i, j, word)) return true;
// 			}
// 		}
// 		return false;
// 	}
// };