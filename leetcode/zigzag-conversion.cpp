class Solution {
public:
    string convert(string s, int numRows) {
    	if (numRows == 1) return s;
    	string zigzag;
    	int len = s.length();
    	for (int i = 0; i < numRows; i++) {
    		int index = i;
    		int step = numRows - 1;
    		int pivot = 0 + step;
    		while (index < len) {
    			zigzag += s[index];
    			while (pivot <= index) {
    				pivot += step;
    			}
    			index = pivot * 2 - index;
    		}
    	}
    	return zigzag;        
    }
};