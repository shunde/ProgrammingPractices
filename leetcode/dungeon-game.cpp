class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.empty() || dungeon[0].empty()) return 0;
        int rows = dungeon.size();
        int cols = dungeon[0].size();
        // health[i][j] -> least health before enter room(i,j)
        vector<vector<int>> health(rows, vector<int>(cols, 0));

        health[rows-1][cols-1] = max(1, 1 - dungeon[rows-1][cols-1]);

        // last row
        for (int j = cols - 2; j >= 0; j--) {
        	health[rows-1][j] = max(1, health[rows-1][j+1] - dungeon[rows-1][j]);
        }

        for (int i = rows-2; i >= 0; i--) {
        	// last col at #row i
        	health[i][cols-1] = max(1, health[i+1][cols-1] - dungeon[i][cols-1]);

        	for (int j = cols-2; j >= 0; j--) {
        		health[i][j] = max(1, min(health[i+1][j], health[i][j+1]) - dungeon[i][j]);
        	}

        }
        return health[0][0];
        
    }
};