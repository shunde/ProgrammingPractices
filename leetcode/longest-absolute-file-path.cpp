class Solution {
public:
	int lengthLongestPath(string input) {
		stack<int> depth_stack;
		int stack_sum = 0;
		int depth = 0;
		int longest_sofar = 0;
		int length = 0;
		bool isfile = false;
		for (int i = 0; i < input.length(); ++i) {
			if (input[i] == '\t')
				++depth;
			else if (input[i] == '.') {
				++length;
				isfile = true;
			} else if (input[i] == '\n') {
				while (depth < depth_stack.size()) {
					stack_sum -= depth_stack.top();
					depth_stack.pop();
				}
				if (isfile) {
					int path_len = stack_sum + depth + length;
					if (path_len > longest_sofar)
						longest_sofar = path_len;
				} else {
					stack_sum += length;
					depth_stack.push(length);
				}

				// back to default.
				length = 0;
				depth = 0;
				isfile = false;
			} else {
				++length;
			}
		}

		if (isfile) {
			int path_len = stack_sum + depth + length;
			if (path_len > longest_sofar)
				longest_sofar = path_len;
		}
		return longest_sofar;
	}
};