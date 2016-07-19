class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    	if (numCourses < 2) return true;
    	vector<vector<int>> graph(numCourses, vector<int> ());
    	vector<int> indegrees(numCourses, 0);

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

    		for (auto w: graph[v]) {
    			indegrees[w]--;
    			if (indegrees[w] == 0)
    				workq.push(w);
    		}
    	}

    	if (leftVertexs > 0) return false;
    	return true;
    }
};