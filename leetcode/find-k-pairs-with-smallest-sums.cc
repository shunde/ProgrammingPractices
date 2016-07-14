class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    	int n, m;
    	n = nums1.size();
    	m = nums2.size();
    	if (n == 0 || m == 0 || k <= 0) return vector<pair<int, int>>();
    	if (k > n * m)
    		k = n * m;
    	
    	struct Cell {    	
    		int x, y;
    		int value;
    		Cell(int _x, int _y, int _value): x(_x), y(_y), value(_value) {}    		
    	};
    	struct Comp {
    		bool operator() (const Cell& lhs, const Cell& rhs) {
    			return lhs.value > rhs.value;
    		}
    	};
    	auto toindex = [m](int x, int y) {
    		return x*m+y;
    	};
    	vector<pair<int, int>> result;
    	unordered_set<int> visited;
    	priority_queue<Cell, vector<Cell>, Comp> workq;

    	workq.push(Cell(0, 0, nums1[0]+nums2[0]));
    	visited.insert(toindex(0, 0));
    	while (!workq.empty()) {
    		Cell cur = workq.top();
    		workq.pop();
    		int x = cur.x, y = cur.y;
    		result.push_back(make_pair(nums1[x], nums2[y]));

    		if (result.size() == k) break;
    		
    		if (x+1 < n && visited.find(toindex(x+1, y)) == visited.end()) {
    			workq.push(Cell(x+1, y, nums1[x+1]+nums2[y]));
    			visited.insert(toindex(x+1, y));
    		}
    		if (y+1 < m && visited.find(toindex(x, y+1)) == visited.end()) {
    			workq.push(Cell(x, y+1, nums1[x]+nums2[y+1]));
    			visited.insert(toindex(x, y+1));
    		}
    	}
    	return result;        
    }
};