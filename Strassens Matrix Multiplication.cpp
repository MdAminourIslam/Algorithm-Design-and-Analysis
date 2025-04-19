#include <bits/stdc++.h>
using namespace std;

// Function to add two matrices
vector<vector<int>> addMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

// Function to subtract two matrices
vector<vector<int>> subtractMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

// Strassen's matrix multiplication
vector<vector<int>> strassen(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();

    // Base case for recursion
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    // Divide the matrices into 4 submatrices
    int k = n / 2;
    vector<vector<int>> A11(k, vector<int>(k)), A12(k, vector<int>(k)), A21(k, vector<int>(k)), A22(k, vector<int>(k));
    vector<vector<int>> B11(k, vector<int>(k)), B12(k, vector<int>(k)), B21(k, vector<int>(k)), B22(k, vector<int>(k));

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    // Compute the 7 Strassen products
    auto p = strassen(addMatrix(A11, A22), addMatrix(B11, B22));
    auto q = strassen(B11, addMatrix(A21, A22));
    auto r = strassen(A11, subtractMatrix(B12, B22));
    auto s = strassen(A22, subtractMatrix(B21, B11));
    auto t = strassen(B22, addMatrix(A11, A12));
    auto u = strassen(subtractMatrix(A21, A11), addMatrix(B11, B12));
    auto v = strassen(addMatrix(B21, B22), subtractMatrix(A12, A22));

    // Combine the results into the resulting matrix C
    vector<vector<int>> C(n, vector<int>(n));
    for(int i = 0; i < k; ++i) {
        for(int j = 0; j < k; ++j) {
            C[i][j] = p[i][j] + s[i][j] - t[i][j] + v[i][j];
            C[i][j + k] = r[i][j] + t[i][j];
            C[i + k][j] = q[i][j] + s[i][j];
            C[i + k][j + k] = p[i][j] + r[i][j] - q[i][j] + u[i][j];
        }
    }

    return C;
}

int main() {
    int n; cin >> n;

    // Ensure n is a power of 2 (for simplicity)
    int size = 1;
    while (size < n) size *= 2;

    vector<vector<int>> A(size, vector<int>(size, 0));
    vector<vector<int>> B(size, vector<int>(size, 0));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> B[i][j];

    auto C = strassen(A, B);

    // Output result
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

