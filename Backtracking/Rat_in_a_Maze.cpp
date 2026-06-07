#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solveMazeUtil(vector<vector<int>>& maze, int x, int y, int n,
                   vector<string>& result, string path) {
    if (x == n - 1 && y == n - 1) {
        result.push_back(path);
        return;
    }
    int dx[] = {1, 0, 0, -1};
    int dy[] = {0, -1, 1, 0};
    char dir[] = {'D', 'L', 'R', 'U'};
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx >= 0 && ny >= 0 && nx < n && ny < n && maze[nx][ny] == 1) {
            maze[nx][ny] = 0;
            solveMazeUtil(maze, nx, ny, n, result, path + dir[k]);
            maze[nx][ny] = 1;
        }
    }
}

vector<string> solveMaze(vector<vector<int>>& maze) {
    int n = maze.size();
    vector<string> result;
    if (maze[0][0] == 0) return result;
    maze[0][0] = 0;
    solveMazeUtil(maze, 0, 0, n, result, "");
    return result;
}

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    vector<string> result = solveMaze(maze);
    for (string& path : result) cout << path << " ";
    cout << "\n";
    return 0;
}
