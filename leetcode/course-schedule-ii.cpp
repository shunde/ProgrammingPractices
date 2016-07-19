class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    	if (numCourses == 0) return vector<int> ();
        vector<vector<int>> graph(numCourses, vector<int> ());
    	vector<int> indegrees(numCourses, 0);
    	vector<int> order;

    	for (auto &edge: prerequisites) {
    		indegrees[edge.first]++;
    		graph[edge.second].push_back(edge.first);
    	}        

    	queue<int> workq;
    	for (int i = 0; i < numCourses; i++) {
    		if (indegrees[i] == 0)
    			workq.push(i);
    	}
    	int leftVertexs = numCourses;
    	while (!workq.empty()) {
    		int v = workq.front();
    		workq.pop();
    		leftVertexs--;
    		order.push_back(v);

    		for (auto w: graph[v]) {
    			indegrees[w]--;
    			if (indegrees[w] == 0)
    				workq.push(w);
    		}
    	}

    	if (leftVertexs > 0) return vector<int>();
    	return order;
    }
};