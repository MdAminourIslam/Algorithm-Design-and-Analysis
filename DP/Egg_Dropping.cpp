#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int eggDrop(int eggs, int floors) {
    vector<vector<int>> dp(eggs + 1, vector<int>(floors + 1, 0));
    for (int i = 1; i <= eggs; i++) {
        dp[i][1] = 1;
        dp[i][0] = 0;
    }
    for (int j = 1; j <= floors; j++) dp[1][j] = j;
    for (int i = 2; i <= eggs; i++) {
        for (int j = 2; j <= floors; j++) {
            dp[i][j] = INT_MAX;
            int low = 1, high = j;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                int broken = dp[i - 1][mid - 1];
                int notBroken = dp[i][j - mid];
                int worst = 1 + max(broken, notBroken);
                dp[i][j] = min(dp[i][j], worst);
                if (broken > notBroken) high = mid - 1;
                else low = mid + 1;
            }
        }
    }
    return dp[eggs][floors];
}

int main() {
    cout << "2 eggs, 10 floors: " << eggDrop(2, 10) << " attempts\n";
    cout << "3 eggs, 14 floors: " << eggDrop(3, 14) << " attempts\n";
    return 0;
}
