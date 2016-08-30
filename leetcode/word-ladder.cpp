/**
 * refer to http://www.programcreek.com/2012/12/leetcode-word-ladder/
 */
class Solution {
private:
	struct WordNode {
		string word;
		int step;
		WordNode(string w, int s): word(w), step(s) {}
	};
public:
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
		queue<WordNode> workq;
		workq.push(WordNode(beginWord, 1));
		wordList.insert(endWord);

		while (!workq.empty()) {
			WordNode top = workq.front();
			string word = top.word;
			workq.pop();
			if (word.compare(endWord) == 0) return top.step;
			for (int i = 0; i < word.length(); i++) {
				char temp = word[i];
				for (char c = 'a'; c <= 'z'; c++) {
					if (temp != c) {
						word[i] = c;
						if (wordList.find(word) != wordList.end()) {
							workq.push(WordNode(word, top.step + 1));
							wordList.erase(word);
						}
					}
				}
				word[i] = temp;
			}
		}
		return 0;
	}
};