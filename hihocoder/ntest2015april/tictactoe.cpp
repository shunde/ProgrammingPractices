#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool isValid(vector<vector<char>> &grid) {
    int m, n;
    int xcount, ocount;
    m = grid.size();
    n = grid[0].size();
    for (int i=0; i <m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'X')
                xcount++;
            else if (grid[i][j] == 'O')
                ocount++;
        }
    }
    if (ocount == xcount || ocount == xcount-1) return true;
    return false;
}


char whoWin(vector<vector<char>> &grid) {
    char win = '_'; // draw
    bool finish = false;
    // row
    for (int i = 0; i < grid.size(); i++) {
        char x = grid[i][0];
        int j = 1;
        for (; j < grid[0].size(); j++)
            if (x != grid[i][j])
                break;
        if (j == grid[0].size()) {
            win = x;
            return win;
        }
    }
    // col
    for (int j = 0; i < grid[0].size(); j++) {
        char x = grid[0][j];
        int i = 1;
        for (; i < grid.size(); i++)
            if (x != grid[i][j])
                break;
        if (i == grid.size()) {
            win = x;
            return win;
        }
    }


    char x = grid[0][0];
    int i, j;
    for (i = 1, j = 1; i < grid.size(); i++, j++) {
        if (x != grid[i][j])
            break;
    }
    if (i == grid.size()) return x;

    i = 0, j = grid[0].size() - 1;
    x = grid[i][j];
    for (; i < grid.size(); i++, j--)
        if (x != grid[i][j])
            break;

    if (i == grid.size()) return x;

    return win;
}
