class Solution {
private:
	void do_calculate(stack<int>& operands, stack<char>& ops) {
		int b = operands.top(); operands.pop();
		int a = operands.top(); operands.pop();
		char op = ops.top(); ops.pop();
		int ret = 0;
		switch (op) {
		case '+':
			ret = a + b;
			break;
		case '-':
			ret = a - b;
			break;
		default:
			// not happen
			break;
		}
		operands.push(ret);
	}
public:
	int calculate(string s) {
		stack<int> operands;
		stack<char> ops;
		int idx = 0;
		for (; idx < s.length(); ) {
			if (isdigit(s[idx])) {
				int val = 0;
				while (idx < s.length() && isdigit(s[idx])) {
					val = val * 10 + s[idx] - '0';
					++idx;
				}
				operands.push(val);
			} else if (s[idx] == '(') {
				ops.push(s[idx]);
				++idx;
			} else if (s[idx] == ')') {
				while (!ops.empty() && ops.top() != '(') {
					do_calculate(operands, ops);
				}
				if (!ops.empty() && ops.top() == '(') ops.pop();
				++idx;
			} else if (s[idx] == '+' || s[idx] == '-') {
				while (!ops.empty() && ops.top() != '(') {
					do_calculate(operands, ops);
				}
				ops.push(s[idx]);
				++idx;
			} else {
				++idx;
			}
		}
		while (!ops.empty()) {
			do_calculate(operands, ops);
		}
		return operands.top();
	}
};