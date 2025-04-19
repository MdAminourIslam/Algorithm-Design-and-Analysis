#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int LPS(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Every single character is a palindrome of length 1
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    // Build the dp array
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    string s;
    cin >> s;
    cout << "Length of LPS: " << LPS(s) << endl;
    return 0;
}

