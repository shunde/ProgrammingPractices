#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

class Node {
    int xPos;
    int yPos;
    int cost;
    int priority;
    Node *parent;
public:
    Node(int x, int y, int c, Node *parent = NULL): xPos(x), yPos(y), cost(c), priority(0), parent(parent) {}
    int getXPos() const { return xPos; }
    int getYPos() const { return yPos; }
    int getCost() const { return cost; }
    int getPriority() const { return priority; }
    const Node* getParent() const { return parent; }

    void updatePriority(const int &xDest, const int &yDest) {
        priority = cost + estimate(xDest, yDest);
    }
private:
    int estimate(const int &xDest, const int &yDest) {
        int hcost = abs(yDest - yPos);
        int vcost = xDest < xPos ? 3 * (xPos - xDest) : 0;
        return hcost + vcost;
    }
};

struct Comparator {
    bool operator ()(const Node *lhs, const Node *rhs) {
        return lhs->getPriority() > rhs->getPriority();
    }

};


void printPath(const Node* node) {
    if (node == NULL) return;
    printPath(node->getParent());
    if (node->getParent() != NULL) {
        cout << ",";
    }
    cout << "[" << node->getXPos() << "," << node->getYPos() << "]";

}
void escapeMaze(const vector<vector<int>> &maze, int health) {
    int n = maze.size();
    int m = maze[0].size();
    bool findPath = false;
    priority_queue<Node*, vector<Node*>, Comparator> pq;
    vector<vector<bool>> tried(n, vector<bool>(m, false));
    int xFinish = 0, yFinish = m - 1;

    Node* node = new Node(0, 0, 0, NULL);
    node->updatePriority(xFinish, yFinish);
    pq.push(node);

    while (!pq.empty()) {
        Node* node = pq.top();
        pq.pop();

        int x = node->getXPos(), y = node->getYPos();
        tried[x][y] = true;

        if (x == xFinish && y == yFinish) {
            if (node->getCost() > health) break;
            findPath = true;
            printPath(node);
            cout << endl;
            break;
        }

        if (node->getCost() >= health) break;

        if (x - 1 >= 0 && maze[x - 1][y] == 1 && !tried[x - 1][y]) {
            Node* new_node = new Node(x - 1, y, node->getCost()+3, node);
            new_node->updatePriority(xFinish, yFinish);
            pq.push(new_node);
        }


        if (x + 1 < n  && maze[x + 1][y] == 1 && !tried[x + 1][y]) {
            Node* new_node = new Node(x + 1, y, node->getCost(), node);
            new_node->updatePriority(xFinish, yFinish);
            pq.push(new_node);
        }


        if (y - 1 >= 0  && maze[x][y - 1] == 1 && !tried[x][y - 1]) {
            Node* new_node = new Node(x, y - 1, node->getCost()+1, node);
            new_node->updatePriority(xFinish, yFinish);
            pq.push(new_node);
        }


        if (y + 1 < m  && maze[x][y + 1] == 1 && !tried[x][y + 1]) {
            Node* new_node = new Node(x, y + 1, node->getCost()+1, node);
            new_node->updatePriority(xFinish, yFinish);
            pq.push(new_node);
        }

    }

    if (!findPath)
        cout << "Can not escape!" << endl;

}

int main() {
    int n, m, p;
    cin >> n >> m >> p;
    vector<vector<int>> maze(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }
    escapeMaze(maze, p);
    return 0;
}
