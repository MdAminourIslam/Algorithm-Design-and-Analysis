#include<bits/stdc++.h>
using namespace std;

void OddMagicSquare(int n) {
    int Msquare[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Msquare[i][j] = 0;
        }
    }

    int num = 1;
    int i = 0, j = n / 2;

    while (num <= n * n) {
        Msquare[i][j] = num++;

        int newi = i - 1;
        int newj = j + 1;
        if(newi >= 0 && newi < n && newj >= 0 && newj < n) {
            if (Msquare[newi][newj]) {
                i += 1;
            } else {
                i = newi, j = newj;
            }
        }
        else if (newi < 0 && newj >= n) { // top right corner
            i += 1;
        }
        else {
            if (newi < 0) {
                i = n - 1, j = newj;
            } else {
                i = newi, j = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(4) << Msquare[i][j];
        }
        cout << "\n";
    }
}

int main() {
    int n; cin >> n;
    if (n % 2 == 0 || n < 1) {
        cout << "Please enter a positive odd number." << "\n";
    } else {
        OddMagicSquare(n);
    }
    return 0;
}
