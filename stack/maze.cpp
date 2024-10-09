// main.cpp
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int direction[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

struct Node {
    int x;
    int y;
    int dir;
    Node(int x, int y, int dir): x(x), y(y), dir(dir) {}
};

bool isValid(int x, int y, vector<vector<int>>& maze, vector<vector<bool>>& visited) {
    int n = maze.size();
    int m = maze[0].size();
    return (x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == 1 && !visited[x][y]);
}

bool solveMaze(vector<vector<int>>& maze, int startX, int startY, int endX, int endY) {
    int n = maze.size();
    int m = maze[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    stack<Node> s;
    s.push(Node(startX, startY, 0));
    visited[startX][startY] = true;
    while (!s.empty()) {
        Node current = s.top();
        s.pop();
        if (current.x == endX && current.y == endY) {
            return true;
        }
        while (current.dir < 4) {
            int newX = current.x + direction[current.dir][0];
            int newY = current.y + direction[current.dir][1];
            current.dir++;
            if (isValid(newX, newY, maze, visited)) {
                s.push(current);
                s.push(Node(newX, newY, 0));
                visited[newX][newY] = true;
                break;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<int>> maze = {
            {1, 0, 1, 1, 0},
            {1, 1, 1, 0, 1},
            {0, 1, 0, 1, 1},
            {1, 1, 1, 1, 1}
    };

    int startX = 0, startY = 0;
    int endX = 3, endY = 3;

    if (solveMaze(maze, startX, startY, endX, endY)) {
        cout << "ok" << endl;
    } else {
        cout << "没有找到路径。" << endl;
    }

    return 0;
}
