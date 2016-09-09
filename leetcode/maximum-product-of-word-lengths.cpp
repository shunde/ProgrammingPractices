class Solution {
  struct WordInfo {
    int len;
    unsigned long bitset;
    WordInfo(int len, unsigned long bitset) : len(len), bitset(bitset) {}
  };

 public:
  int maxProduct(vector<string>& words) {
    //if (words.empty()) return 0;

    vector<WordInfo> wordinfos;
    {
      std::bitset<26> mybitset;
      for (auto& word : words) {
        mybitset.reset();
        for (auto c : word) {
          mybitset.set(c - 'a');
        }
        wordinfos.push_back(WordInfo(word.length(), mybitset.to_ulong()));
      }
    }

    int result = 0;
    for (int i = 0; i < wordinfos.size(); i++) {
      for (int j = i + 1; j < wordinfos.size(); j++) {
        if (!(wordinfos[i].bitset & wordinfos[j].bitset)) {
          result = max(result, wordinfos[i].len * wordinfos[j].len);
        }
      }
    }

    return result;
  }
};