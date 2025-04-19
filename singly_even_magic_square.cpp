#include<bits/stdc++.h>
using namespace std;
int temp[100][100];

void OddMagicSquare(int n, int startvalue, int lastvalue) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = 0;
        }
    }

    int num = startvalue;
    int i = 0, j = n / 2;

    while (num <= lastvalue) {
        temp[i][j] = num++;

        int newi = i - 1;
        int newj = j + 1;
        if (newi >= 0 && newi < n && newj >= 0 && newj < n) {
            if (temp[newi][newj]) {
                i += 1;
            } else {
                i = newi, j = newj;
            }
        }
        else if (newi < 0 && newj >= n) {
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
}

void SinglyMagicSquare(int n) {
    int Msquare[n][n];

    int sz = n / 2;

    OddMagicSquare(sz, 1, sz * sz);
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            Msquare[i][j] = temp[i][j];
        }
    }

    OddMagicSquare(sz, sz * sz + 1, 2 * sz * sz);
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            Msquare[i + sz][j + sz] = temp[i][j];
        }
    }

    OddMagicSquare(sz, 2 * sz * sz + 1, 3 * sz * sz);
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            Msquare[i][j + sz] = temp[i][j];
        }
    }

    OddMagicSquare(sz, 3 * sz * sz + 1, 4 * sz * sz);
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            Msquare[i + sz][j] = temp[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(4) << Msquare[i][j];
        }
        cout << "\n";
    }
    cout << "\n";

    int center = sz / 2;
    swap(Msquare[center][center], Msquare[center + sz][center]);  //swap center cell of A and D

    for (int i = 0; i < sz; i++) {
        if (i == center) continue;
        swap(Msquare[i][center - 1], Msquare[i + sz][center - 1]); // Swap complete Column 'b' of (A & D) withuot center cell

    }

    for (int j = center - 2; j >= 0; j--) {
        for (int i = 0; i < sz; i++) {
            swap(Msquare[i][j], Msquare[i + sz][j]);  // Swap complete Column 'a' of (A & D)
        }
    }

    for (int j = n - center + 1; j < n; j++) {
        for (int i = 0; i < sz; i++) {
            swap(Msquare[i][j], Msquare[i + sz][j]);   // Swap complete Column 'a' of (C & B)
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
    if(n > 2 && n % 2 == 0 && n % 4 != 0) {
        SinglyMagicSquare(n);
    } else {
        cout << "Please Enter an singly even number" << "\n";
    }
}
