class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> monotone_stack;
        heights.push_back(-1);    // end mark

        int idx = 0;
        int maxArea = 0;
        
        while(idx < heights.size()) {

        	if (monotone_stack.empty() 
        		|| heights[monotone_stack.top()] <= heights[idx]) {
        		monotone_stack.push(idx);
        		idx++;
        	} else {
        		int top = monotone_stack.top();
        		monotone_stack.pop();
        		int area = 0;
        		if (monotone_stack.empty())
        			area = heights[top] * idx;
        		else
        			area = heights[top] * (idx - monotone_stack.top() - 1);

        		if (area > maxArea)
        			maxArea = area;
        	}
        }
    	return maxArea;
    }
};