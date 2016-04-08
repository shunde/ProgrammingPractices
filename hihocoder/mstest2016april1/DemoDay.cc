#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int minFlipGrids(vector<vector<char> > &grid) {
    int row, col;
    if (!(row = grid.size()) || !(col = grid[0].size())) return 0;

    if (row == 1 && col == 1) return 0;

    vector<vector<int> > dp(col, vector<int>(2, 0));

    dp[0][0] = 0;
    for (int i = 1; i < col; i++) {
        if (grid[0][i] == 'b')
            dp[i][0] = dp[i - 1][0] + 1;
        else
            dp[i][0] = dp[i - 1][0];
    }

    for (int i = 0; i < col - 1 ; i++) {
        if (grid[0][i + 1] != 'b')
            dp[i][1] = dp[i][0] + 1;
        else
            dp[i][1] = dp[i][0];
    }
    dp[col - 1][1] = dp[col - 1][0];


    for (int i = 1; i < row - 1; i++) {

        vector<vector<int> > oldp(dp.begin(), dp.end());

        dp[0][1] = grid[i][0] == 'b' ? oldp[0][1] + 1 : oldp[0][1];
        dp[0][0] = grid[i + 1][0] != 'b' ? oldp[0][1] + 1 : oldp[0][1];
        for (int j = 1; j < col; j++) {
            if (grid[i][j] == 'b') {
                dp[j][0] = 1 + min(oldp[j-1][0], grid[i+1][j] == 'b'?oldp[j][1]:oldp[j][1]+1);
            } else {
                
            }
    }
}