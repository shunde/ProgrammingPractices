class Solution {
private:
	// assume that all inputs are consist of lowercase letters a-z
	class Trie {
	public:
		Trie() {
			isword = false;
			for (int i = 0; i < 26; i++)
				subTries[i] = nullptr;
		}
		void addWord(const string &word) {
			addWordAux(this, word, 0);		
		}
		Trie* getSubTrie(char c) {
			int idx = c - 'a';
			return subTries[idx];
		}
		bool isWord() {
			return isword;
		}
		string getWord() {
			return word;
		}		
		~Trie() {
			for (int i = 0; i < 26; i++) {
				if (subTries[i])
					delete subTries[i];
			}
		}
	private:
		Trie* addWordAux(Trie* root, const string& word, int k) {
			if (!root) root = new Trie();
			if (k == word.length()) {
				root->isword = true;
				root->word = word;
			} else {
				int idx = word[k] - 'a';
				root->subTries[idx] = addWordAux(root->subTries[idx], word, k+1);
			}
			return root;
		}
	private:
		Trie* subTries[26];
		bool isword;
		string word;
	};
	void dfs(vector<vector<char>>& board, Trie *root, int i, int j, unordered_set<string>& result) {
		if (!root) return;
		int rows = board.size();
		int cols = board[0].size();
		if (i < 0 || i >= rows || j < 0 || j >= cols) return;
		if (board[i][j] == '#') return;
		
		Trie* pTrie = root->getSubTrie(board[i][j]);
		if (pTrie) {
			if (pTrie->isWord()) result.insert(pTrie->getWord());
			char temp = board[i][j];
			board[i][j] = '#';

			dfs(board, pTrie, i-1, j, result);
			dfs(board, pTrie, i+1, j, result);
			dfs(board, pTrie, i, j-1, result);
			dfs(board, pTrie, i, j+1, result);

			board[i][j] = temp;
		}
	}
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {    	
    	vector<string> result;

    	if (board.empty() || board[0].empty() || words.empty()) return result;

    	Trie *pTrie = new Trie();
    	for (auto& w: words) {
    		pTrie->addWord(w);
    	}

    	unordered_set<string> myset;
    	int rows = board.size();
    	int cols = board[0].size();
    	for (int i = 0; i < rows; i++) {
    		for (int j = 0; j < cols; j++) {
    			dfs(board, pTrie, i, j, myset);
    		}
    	}

    	for (auto& w: myset) {
    		result.push_back(w);
    	}

    	return result;        
    }
};