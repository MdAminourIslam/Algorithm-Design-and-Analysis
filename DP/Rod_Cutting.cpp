#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rodCutting(vector<int>& price, int n) {
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            dp[i] = max(dp[i], price[j - 1] + dp[i - j]);
    return dp[n];
}

int main() {
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = 8;
    cout << "Max profit for rod length " << n << ": " << rodCutting(price, n) << "\n";
    return 0;
}
