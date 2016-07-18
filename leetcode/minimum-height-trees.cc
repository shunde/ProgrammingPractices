class Solution {
private:
	class Graph {
		vector<vector<int> > vertexs;
		int n;
	public:
		Graph(int _n) {
			n = _n;
			vertexs = vector<vector<int> > (n, vector<int> ());
		}
		void addEdge(int v, int w) {
			assert(v >= 0 && v < n);
			assert(w >= 0 && w < n);

			vertexs[v].push_back(w);
			vertexs[w].push_back(v);
		}
		const vector<int>& getNeighbors(int v) {
			assert(v >= 0 && v < n);
			return vertexs[v];
		}
	}

	int bfs(const Graph& graph, int v) {

	}
public:
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		if (n == 0) return vector<int> ();
		if (n == 1) return vector<int> {0};

		vector<int> mht(n, -1);
		Graph graph(n);
		for (int i = 0; i < edges.size(); i++) {
			graph.addEdge(edges[i].first, edges[i].second);
		}

		for (int i = 0; i < n; i++) {
			mht[i] = bfs(graph, i);
		}

		
	}
};