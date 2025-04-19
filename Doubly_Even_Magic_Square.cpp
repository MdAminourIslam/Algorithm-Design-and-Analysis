
#include <bits/stdc++.h>
using namespace std;

void doublyEvenMagicSquare(int n) {
    int mini = n / 4, val = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i < mini && j < mini) || (i < mini && j >= n - mini) || (i >= n - mini && j < mini) || (i >= n - mini && j >= n - mini)) {
                cout << setw(4) << val + 1;
                val++;
            }
            else if (i >= mini && i < n - mini && j >= mini && j < n - mini) { // large square
                cout << setw(4) << val + 1;
                val++;
            }
            else {
                cout << setw(4) << (n * n) - val;
                ++val;
            }
        }
        cout << "\n";
    }
}

int main() {
    int n; cin >> n;
    if (n % 4 != 0) {
        cout << "Order must be a multiple of 4 for a doubly even magic square.\n";
    } else {
        doublyEvenMagicSquare(n);
    }
    return 0;
}
