#include <iostream>
#include <vector>
using namespace std;

void dfsUtil(vector<vector<int>>& adj, int u, vector<bool>& visited) {
    visited[u] = true;
    cout << u << " ";
    for (int v : adj[u])
        if (!visited[v]) dfsUtil(adj, v, visited);
}

void dfs(vector<vector<int>>& adj, int start) {
    int n = adj.size();
    vector<bool> visited(n, false);
    dfsUtil(adj, start, visited);
}

int main() {
    int n = 5;
    vector<vector<int>> adj(n);
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};
    cout << "DFS from 0: ";
    dfs(adj, 0);
    cout << "\n";
    return 0;
}
