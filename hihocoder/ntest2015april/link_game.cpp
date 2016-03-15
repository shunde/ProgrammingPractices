#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <climits>
#include <utility>


using namespace std;

typedef pair<int, int> position;

int getLinkNum(vector<vector<int> > &grid, int x, int y, int maxSegment) {
    int m= grid.size();
    int n = grid[0].size();
    int target = grid[x][y];
    vector<vector<bool> > visited(m, vector<bool>(n, false));
    vector<vector<int> > cost(m, vector<int>(n, INT_MAX));
    queue<position> Q;
    int count = 0;
    cost[x][y] = 0;
    Q.push(position(x, y));
    visited[x][y] = true;
    while (!Q.empty()) {
        position cur = Q.front();
        Q.pop();
        
        int segments = cost[cur.first][cur.second];
        if (segments >= maxSegment) break;        

        int startX, startY; 

        startX = cur.first, startY = cur.second;
        // up
        while (--startX >= 0 && visited[startX][startY] == false && grid[startX][startY] == 0) {
            cost[startX][startY] = segments+1;
            visited[startX][startY] = true;
            Q.push(make_pair(startX, startY));
        }
        if (startX >= 0 && visited[startX][startY] == false && grid[startX][startY] == target) {
            count++;
            visited[startX][startY] = true;
        }

        startX = cur.first, startY = cur.second;
        // down
        while (++startX < m && visited[startX][startY] == false && grid[startX][startY] == 0) {
            cost[startX][startY] = segments+1;
            visited[startX][startY] = true;
            Q.push(make_pair(startX, startY));
        }
        if (startX < m && visited[startX][startY] == false && grid[startX][startY] == target) {
            count++;
            visited[startX][startY] = true;
        }

        startX = cur.first, startY = cur.second;
        // left
        while (--startY >= 0 && visited[startX][startY] == false && grid[startX][startY] == 0) {
            cost[startX][startY] = segments+1;
            visited[startX][startY] = true;
            Q.push(make_pair(startX, startY));
        }
        if (startY >= 0 && visited[startX][startY] == false && grid[startX][startY] == target) {
            count++;
            visited[startX][startY] = true;
        }

        startX = cur.first, startY = cur.second;
        // right
        while (++startY < n && visited[startX][startY] == false && grid[startX][startY] == 0) {
            cost[startX][startY] = segments+1;
            visited[startX][startY] = true;
            Q.push(make_pair(startX, startY));
        }
        if (startY < n && visited[startX][startY] == false && grid[startX][startY] == target) {
            count++;
            visited[startX][startY] = true;
        }
    }
    return count;
}

int main(int argc, char *argv[]) {
    int S;
    cin >> S;
    for (int i = 0; i < S; i++) {
        int N, M;
        cin >> N >> M;
        vector<vector<int> > grid(N+2, vector<int>(M+2, 0));
        for (int row = 1; row <= N; row++) 
            for (int col = 1; col <= M; col++) {
                cin >> grid[row][col];
            }
        int x, y, k;
        cin >> x >> y >> k;
        cout << getLinkNum(grid, x, y, k+1) << endl;
    }

    return 0;
}