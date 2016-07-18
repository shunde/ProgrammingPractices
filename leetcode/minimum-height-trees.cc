class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		if (n == 0) return vector<int> ();
		if (n == 1) return vector<int> {0};

		vector<vector<int> > graph(n, vector<int> ());
		vector<int> degrees(n, 0);

		for (auto e : edges) {
			degrees[e.first]++;
			degrees[e.second]++;

			graph[e.first].push_back(e.second);
			graph[e.second].push_back(e.first);
		}

		queue<int> workq;
		for (int i = 0; i < n; i++) {
			if (degrees[i] == 1) {
				workq.push(i);
			}
		}

		while (n > 2) {
			int sz = workq.size();
			for (int i = 0; i < sz; i++)  {
				int v = workq.front();
				workq.pop();
				n--;
				for (auto w : graph[v]) {
					degrees[w]--;
					if (degrees[w] == 1)
						workq.push(w);
				}
			}
		}

		vector<int> result;
		while (!workq.empty()) {
			result.push_back(workq.front());
			workq.pop();
		}

		return result;
	}
};