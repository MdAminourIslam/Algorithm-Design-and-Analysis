#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int col, vector<string> &board, vector<vector<string>> &ans,
               vector<int> &leftRow, vector<int> &upperDiagonal,
               vector<int> &lowerDiagonal, int n) {
        if (col == n) {
            ans.push_back(board); // Add valid board to the result
            return;
        }

        for (int row = 0; row < n; row++) {
            if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 &&
                upperDiagonal[n - 1 + col - row] == 0) {

                // Place queen
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;

                // Recurse for next column
                solve(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);

                // Backtrack
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; // Store all valid solutions
        vector<string> board(n, string(n, '.')); // Initialize empty board

        // Arrays to mark availability
        vector<int> leftRow(n, 0); // Tracks rows
        vector<int> upperDiagonal(2 * n - 1, 0); // Tracks top-left to bottom-right diagonals
        vector<int> lowerDiagonal(2 * n - 1, 0); // Tracks top-right to bottom-left diagonals

        solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n); // Start solving

        return ans;
    }
};

int main() {
    Solution solution;
    int n = 4; // For example, an 8x8 chessboard
    vector<vector<string>> results = solution.solveNQueens(n);

    // Print results
    for(const auto &board : results) {
        for (const string &row : board) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}

