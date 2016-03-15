/**
 * 推箱子
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

const char BLANK = '0';
const char USER = '1';
const char TARGET = '2';
const char BOX = '3';
const char WALL = '4';

struct position {
    int x;
    int y;
    position(): x(-1), y(-1) {}    
};

bool solve(vector<vector<char> > grid, string operation) {
    position user, box, target;
    int m, n;
    if (!(m = grid.size()) || !(n = grid[0].size())) return false;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == USER) {
                user.x = i;
                user.y = j; 
                grid[i][j] = BLANK; // clear user               
            } else if (grid[i][j] == BOX) {
                box.x = i;
                box.y = j;                
            } else if (grid[i][j] == TARGET) {
                target.x = i;
                target.y = j; 
                grid[i][j] = BLANK; // clear target               
            }            
        }
    }
    //bool stop = false;
    bool success = false;
    for (int i = 0; i < operation.length(); i++) {
        char op = operation.at(i);
        
        // up
        if (op == 'u' && user.x > 0) {
            if (grid[user.x-1][user.y] == BLANK) 
                user.x -= 1;
            else if (user.x > 1 && grid[user.x-1][user.y] == BOX && grid[user.x-2][user.y] != WALL) {
                user.x -= 1;
                grid[box.x][box.y] = BLANK;
                box.x -= 1;
                grid[box.x][box.y] = BOX;

            }
        } else if (op == 'd' && user.x < m-1) {
            if (grid[user.x+1][user.y] == BLANK) 
                user.x += 1;
            else if (user.x < m-2 && grid[user.x+1][user.y] == BOX && grid[user.x+2][user.y] != WALL) {
                user.x += 1;
                grid[box.x][box.y] = BLANK;
                box.x += 1;
                grid[box.x][box.y] = BOX;
            }
        } else if (op == 'l' && user.y > 0) {
            if (grid[user.x][user.y-1] == BLANK) 
                user.y -= 1;
            else if (user.y > 1 && grid[user.x][user.y-1] == BOX && grid[user.x][user.y-2] != WALL) {
                user.y -= 1;
                grid[box.x][box.y] = BLANK;
                box.y -= 1;
                grid[box.x][box.y] = BOX;
            }
        } else if (op == 'r' && user.y < n-1) {
            if (grid[user.x][user.y+1] == BLANK) 
                user.y += 1;
            else if (user.y < n-2 && grid[user.x][user.y+1] == BOX && grid[user.x][user.y+2] != WALL) {
                user.y += 1;
                grid[box.x][box.y] = BLANK;
                box.y += 1;
                grid[box.x][box.y] = BOX;
            }
        }

        if (box.x == target.x && box.y == target.y) {
            success = true;
            break;
        }

     }
    return success;
}

int main() {
    int m, n, s;
    cin >> n >> m >> s;
    vector<vector<char> > grid(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++)
            grid[i][j] = str.at(j);
    }
    for (int i = 0; i < s; i++) {
        int t;
        string operation;
        cin >> t >> operation;
        if (solve(grid, operation))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}