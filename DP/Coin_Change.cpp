#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
        for (int coin : coins)
            if (coin <= i) dp[i] = min(dp[i], 1 + dp[i - coin]);
    return dp[amount] > amount ? -1 : dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << "Min coins for " << amount << ": " << coinChange(coins, amount) << "\n";
    amount = 3;
    coins = {2};
    cout << "Min coins for " << amount << ": " << coinChange(coins, amount) << "\n";
    return 0;
}
