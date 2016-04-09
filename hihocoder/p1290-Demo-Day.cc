#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Cost {
    int right;
    int down;
    Cost(): right(0), down(0) {}
};

int minFlipGrids(const vector<vector<char> > &grid) {

    int n, m;
    if (!(n = grid.size()) || !(m = grid[0].size())) return 0;
    if (n == 1 && m == 1) return 0;

    vector<Cost> dp(m, Cost());

    dp[0].right = 0;
    for (int i = 1; i < m; i++) {
        if (grid[0][i] == 'b')
            dp[i].right = dp[i - 1].right + 1;
        else
            dp[i].right = dp[i - 1].right;
    }
    for (int i = 0; i < m - 1; i++) {
        if (grid[0][i + 1] == 'b')
            dp[i].down = dp[i].right;
        else
            dp[i].down = dp[i].right + 1;
    }
    dp[m - 1].down = dp[m - 1].right;

    for (int r = 1; r < n - 1; r++) {
        vector<Cost> old_dp(dp.begin(), dp.end());

        dp[0].down = dp[0].down + (grid[r][0] == 'b' ? 1 : 0);
        dp[0].right = dp[0].down + (grid[r + 1][0] != 'b' ? 1 : 0);

        for (int c = 1; c < m - 1; c++) {
            if (grid[r][c] == 'b') {
                dp[c].down = 1 + min(old_dp[c].down, dp[c - 1].right + (grid[r][c + 1] != 'b' ? 1 : 0));
                dp[c].right = 1 + min(dp[c - 1].right, old_dp[c].down + (grid[r + 1][c] != 'b' ? 1 : 0));
            } else {
                dp[c].down = min(old_dp[c].down, dp[c - 1].right + (grid[r][c + 1] != 'b' ? 1 : 0));
                dp[c].right = min(dp[c - 1].right, old_dp[c].down + (grid[r + 1][c] != 'b' ? 1 : 0));
            }
        }
        if (m >= 2) {
            dp[m - 1].down = min(dp[m - 2].right, old_dp[m - 1].down) + (grid[r][m - 1] == 'b' ? 1 : 0);
        }
    }

    dp[0].right = dp[0].down + grid[n - 1][0] == 'b' ? 1 : 0;
    for (int c = 1; c < m; c++) {
        if (grid[n - 1][c] == 'b') {
            dp[c].right = 1 + min(dp[c - 1].right, dp[c].down);
        } else {
            dp[c].right = min(dp[c - 1].right, dp[c].down);
        }
    }
    return dp[m - 1].right;
}

int main(int argc, char* argv[]) {
    int N, M;
    scanf("%d %d", &N, &M);    
    vector<vector<char> > grid(N, vector<char>(M));
    for (int i = 0; i < N; i++) {
        char buf[120];
        scanf("%s", buf);
        for (int j = 0; j < M; j++) {
            grid[i][j] = buf[j];
        }
    }    
    printf("%d\n", minFlipGrids(grid));
    return 0;
}