class Solution {
public:
	// Bottom-Up solution
    int minimumTotal(vector<vector<int>>& triangle) {
    	int nRows = triangle.size();
    	vector<int> total(nRows, 0);
    	for (int i = 0; i < nRows; i++) {
    		total[i] = triangle[nRows-1][i];
    	}

    	for (int i = nRows-2; i>= 0; i--) {
    		for (int j = 0; j < triangle[i].size(); j++) {
    			total[j] = triangle[i][j] + min(total[j], total[j+1]);
    		} 
    	}
    	return total[0];        
    }
};