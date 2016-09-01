class Solution {
public:
    string addBinary(string a, string b) {
    	std::reverse(a.begin(), a.end());
    	std::reverse(b.begin(), b.end());

    	int lenA = a.length();
    	int lenB = b.length();
    	int i = 0, j = 0;
    	string result;
    	int carry = 0;
    	for (; i < lenA && j < lenB; i++, j++) {
    		int sum = a[i] - '0' + b[j] - '0' + carry;
    		carry = sum / 2;
    		sum = sum % 2;
    		result += (sum == 0)? '0': '1';
    	}
    	while (i < lenA) {
    		int sum = a[i] - '0' + carry;
    		carry = sum / 2;
    		sum = sum % 2;
    		result += (sum == 0)? '0': '1';
    		i++;
    	}       
    	while (j < lenB) {
    		int sum = b[j] - '0' + carry;
    		carry = sum / 2;
    		sum = sum % 2;
    		result += (sum == 0)? '0': '1';
    		j++;
    	} 
    	if (carry) result += '1';
    	std::reverse(result.begin(), result.end());
    	return result;
    }
};