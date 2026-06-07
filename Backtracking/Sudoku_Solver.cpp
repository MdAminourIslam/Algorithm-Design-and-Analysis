#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<vector<char>>& board, int row, int col, char num) {
    for (int x = 0; x < 9; x++) {
        if (board[row][x] == num) return false;
        if (board[x][col] == num) return false;
        if (board[3 * (row / 3) + x / 3][3 * (col / 3) + x % 3] == num) return false;
    }
    return true;
}

bool solve(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (board[i][j] == '.') {
                for (char num = '1'; num <= '9'; num++)
                    if (isValid(board, i, j, num)) {
                        board[i][j] = num;
                        if (solve(board)) return true;
                        board[i][j] = '.';
                    }
                return false;
            }
    return true;
}

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    solve(board);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) cout << board[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
