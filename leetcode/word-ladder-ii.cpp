class Solution {
private:
	struct WordNode {
		string word;
		int numSteps;
		shared_ptr<WordNode> prev;
		WordNode(string _word, int _numSteps, shared_ptr<WordNode> _prev): word(_word), numSteps(_numSteps), prev(_prev) {}
	};
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
    	vector<vector<string>> result;
    	queue<shared_ptr<WordNode>> workq;
    	workq.push(make_shared<WordNode> (beginWord, 1, nullptr));
    	wordList.insert(endWord);    
    	int minSteps = 0;
    	int prevSteps = 0;

    	unordered_set<string> visited;

		while (!workq.empty()) {
			shared_ptr<WordNode> top = workq.front(); 
			workq.pop();
			string word = top->word;
			int currSteps = top->numSteps;
			if (word.compare(endWord) == 0) {
				if (minSteps == 0) {
					minSteps = top->numSteps;
				}
				if (minSteps == top->numSteps && minSteps != 0) {
					// print trace
					vector<string> trace;
					shared_ptr<WordNode> pNode = top;
					while (pNode) {
						trace.push_back(pNode->word);
						pNode = pNode->prev;
					}
					std::reverse(trace.begin(), trace.end());
					result.push_back(trace);	
					continue;				
				}								
			}
			if (prevSteps < currSteps) {
				for (auto key: visited) {
					wordList.erase(key);					
				}
				visited.clear();				
			}
			prevSteps = currSteps;

			for (int i = 0; i < word.length(); i++) {
				char temp = word[i];
				for (char c = 'a'; c <= 'z'; c++) {
					if (temp != c) {
						word[i] = c;
						if (wordList.find(word) != wordList.end()) {
							workq.push(make_shared<WordNode> (word, top->numSteps+1, top));
							visited.insert(word);
						}
					}
				}
				word[i] = temp;
			}
		}
		return result;
    }
};