class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
    	int n = matrix.size();
    	if (k == 1) return matrix[0][0];
    	if (k == n*n) return matrix[n-1][n-1];
    	struct Point {
    		int x, y;
    		Point(int _x, int _y): x(_x), y(_y) {}
    	};
    	typedef pair<int, Point> Item;
    	auto comp = [](const Item&lhs, const Item&rhs) {
    		return lhs.first > rhs.first;
    	};
    	priority_queue<Item, vector<Item>, decltype(comp)> workq(comp);
    	for(int i = 0; i < n; i++) {
    		workq.push(make_pair(matrix[0][i], Point(0, i)));
    	}
    	while (--k > 0) {
    		Item cur = workq.top();
    		workq.pop();
    		Point point = cur.second;
    		if (point.x < n-1) {
    			workq.push(make_pair(matrix[point.x+1][point.y], Point(point.x+1, point.y)));
    		}
    	}
    	return workq.top().first;
    }
};