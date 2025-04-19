#include <bits/stdc++.h>
using namespace std;

int matrixChainMultiplication(vector<int>& dimensions) {
    int n = dimensions.size() - 1; // Number of matrices
    vector<vector<int>> dp(n, vector<int>(n, 0)); // DP table to store minimum costs

    // dp[i][j] represents the minimum number of multiplications needed to multiply matrices from i to j

    for(int len = 2; len <= n; len++) {
        for(int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for(int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i] * dimensions[k + 1] * dimensions[j + 1];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }


    return dp[0][n - 1]; // Minimum cost to multiply the entire chain
}

int main() {
    int n;
    cin >> n; // Number of matrices
    vector<int> dimensions(n + 1);

    for (int i = 0; i <= n; ++i) {
        cin >> dimensions[i]; // Dimensions of matrices
    }

    cout << "Minimum number of multiplications: " << matrixChainMultiplication(dimensions) << endl;

    return 0;
}

