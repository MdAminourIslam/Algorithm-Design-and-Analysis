#include<bits/stdc++.h>
using namespace std;

int main() {
    string x, y;
    cout << "Enter First string : ";
    cin >> x;
    cout << "Enter Second string : ";
    cin >> y;
    int n = x.size(), m = y.size();
    int c[n + 1][m + 1];
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            c[i][j] = 0;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(x[i - 1] == y[j - 1]) {
                c[i][j] = 1 + c[i - 1][j - 1];
            } else {
                c[i][j] = max(c[i][j - 1], c[i - 1][j]);
            }
        }
    }

    cout << "Length of LCS = " << c[n][m] << "\n";

    int row = n, col = m;
    string lcs;
    while(row > 0 && col > 0) {
        if(x[row - 1] == y[col - 1]) {
            lcs += x[row - 1];
            row--, col--;
        } else {
            if(c[row - 1][col] >= c[row][col - 1]) {
                row -= 1;
            } else {
                col -= 1;
            }
        }
    }
    reverse(lcs.begin(), lcs.end());
    cout << lcs << "\n";

    return 0;
}
