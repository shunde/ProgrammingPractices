class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
    	if (denominator == 0) return "inf";

    	bool negsign = false;
    	if ((numerator > 0 && denominator < 0) || (numerator < 0 && denominator > 0))
    		negsign = true;

    	long long num = abs((long long)numerator);
    	long long den = abs((long long)denominator);
    	
    	long long intpart = num / den;
    	num = num % den;

    	// 整除
    	if (num == 0) return (negsign ? "-" : "") + to_string(intpart);

    	// 小数部分
    	vector<char> decpart;
    	unordered_map<long long, int> mymap;

    	while (num != 0) {
    		if (mymap.find(num) != mymap.end()) {
    			int idx = mymap[num];
    			auto it = decpart.begin();
    			std::advance(it, idx);
    			decpart.insert(it, '(');
    			decpart.push_back(')');
    			break;
    		}
    		mymap[num] = decpart.size();
    		num *= 10;
    		int quot = num / den;
    		num %= den;
    		decpart.push_back(quot + '0');

    	}

    	string decstr(decpart.begin(), decpart.end());

    	if (negsign)
    		return "-" + to_string(intpart) + "." + decstr;
    	else 
    		return to_string(intpart) + "." + decstr;
    }
};