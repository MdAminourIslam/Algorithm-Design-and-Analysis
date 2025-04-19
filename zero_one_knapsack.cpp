#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, Bag_Size;
    cout << "Enter number of item and bagSize :";
    cin >> n >> Bag_Size;
    vector<int> Weight(n + 1), benefit(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> Weight[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> benefit[i];
    }


    int dp[n + 1][Bag_Size + 1];
    for(int i = 0; i <= n; i++) {
        for(int w = 0; w <= Bag_Size; w++) {
            if(i == 0 || w == 0) {
                dp[i][w] = 0;
            } else {
                if(Weight[i] <= w) {
                    dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - Weight[i]] + benefit[i]);
                } else {
                    dp[i][w] = dp[i - 1][w];
                }
            }
        }
    }

    cout << dp[n][Bag_Size] << "\n";
    return 0;
}
