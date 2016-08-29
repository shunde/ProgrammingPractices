class Solution {
private:
	void do_calculate(stack<int> &operands, stack<char>& ops) {
		int b = operands.top();
		operands.pop();
		int a = operands.top();
		operands.pop();
		char op = ops.top();
		ops.pop();
		int val = do_calculate_aux(a, b, op);
		operands.push(val);
	}
	int do_calculate_aux(int a, int b, char op) {
		int ret = 0;
		switch (op) {
		case '+':
			ret = a + b;
			break;
		case '-':
			ret = a - b;
			break;
		case '*':
			ret = a * b;
			break;
		case '/':
			ret = a / b;
			break;
		default:
			// not happen here.
			break;
		}
		return ret;
	}
public:
	int calculate(string s) {
		stack<int> operands;
		stack<char> ops;
		int idx = 0;
		for (; idx < s.length(); ) {
			if (s[idx] >= '0' && s[idx] <= '9') {
				int val = 0;
				while (idx < s.length && s[idx] >= '0' && s[idx] <= '9') {
					val = val * 10 + s[idx] - '0';
					++idx;
				}
				operands.push(val);
			} else if (s[idx] == '+' || s[idx] == '-') {
				while (!ops.empty()) {
					do_calculate(operands, ops);
				}
				ops.push(s[idx]);
				++idx;
			} else if (s[idx] == '*' || s[idx] == '/') {
				while (!ops.empty() && (ops.top() == '*' || ops.top() == '/')) {
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