#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

// Function to solve TSP using Dynamic Programming and Bitmasking
int tsp(int pos, int mask, int n, vector<vector<int>>& dist, vector<vector<int>>& dp) {
    if (mask == (1 << n) - 1) { // All cities visited
        return dist[pos][0];   // Return to the starting city
    }

    if (dp[pos][mask] != -1) return dp[pos][mask];

    int answer = INF;
    for(int city = 0; city < n; city++) {
        if((mask & (1 << city)) == 0) { // If city is not visited
            int newAnswer = dist[pos][city] + tsp(city, mask | (1 << city), n, dist, dp);
            answer = min(answer, newAnswer);
        }
    }

    return dp[pos][mask] = answer;
}

int main() {
    int n; // Number of cities
    cout << "Enter number of cities: ";
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n));
    cout << "Enter distance matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(1 << n, -1)); // DP table
    int result = tsp(0, 1, n, dist, dp); // Start from city 0 with only city 0 visited

    cout << "The minimum cost of the tour is: " << result << endl;
    return 0;
}


