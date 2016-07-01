class Solution {
private:
	int largestRectangleArea(const vector<int>& heights) {
		stack<int> monotone_stack;
		vector<int> hists(heights.begin(), heights.end());
		hists.push_back(-1);    // end mark

		int idx = 0;
		int maxArea = 0;

		while (idx < hists.size()) {

			if (monotone_stack.empty()
			        || hists[monotone_stack.top()] <= hists[idx]) {
				monotone_stack.push(idx);
				idx++;
			} else {
				int top = monotone_stack.top();
				monotone_stack.pop();
				int area = 0;
				if (monotone_stack.empty())
					area = hists[top] * idx;
				else
					area = hists[top] * (idx - monotone_stack.top() - 1);

				if (area > maxArea)
					maxArea = area;
			}
		}
		return maxArea;
	}
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		int row, col;
		int maxRect = 0;
		if ((row = matrix.size()) == 0 || (col = matrix[0].size()) == 0)
			return 0;

		vector<int> heights(col, 0);
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (matrix[i][j] == '1')
					heights[j] = heights[j] + 1;
				else
					heights[j] = 0;
			}
			int area = largestRectangleArea(heights);
			if (area > maxRect)
				maxRect = area;
		}
		return maxRect;
	}
};