class Solution {
public:
	string reverseVowels(string s) {
		auto isVowels = [](const char& ch) -> bool {
			auto c = tolower(ch);
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
				return true;
			return false;
		};
		int i = 0;
		int j = s.length() - 1;
		while (i < j) {
			while (!isVowels(s[i])) i++;
			while (!isVowels(s[j])) j--;
			if (i < j) {
				swap(s[i], s[j]);
				i++;
				j--;
			} else
				break;
		}
		return s;
	}
};