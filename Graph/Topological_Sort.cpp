#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topologicalSort(vector<vector<int>>& adj, int n) {
    vector<int> indegree(n, 0), result;
    for (int u = 0; u < n; u++)
        for (int v : adj[u]) indegree[v]++;
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0) q.push(i);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        result.push_back(u);
        for (int v : adj[u])
            if (--indegree[v] == 0) q.push(v);
    }
    return result;
}

int main() {
    int n = 6;
    vector<vector<int>> adj(n);
    adj[5] = {2, 0};
    adj[4] = {0, 1};
    adj[2] = {3};
    adj[3] = {1};
    vector<int> order = topologicalSort(adj, n);
    cout << "Topological order: ";
    for (int v : order) cout << v << " ";
    cout << "\n";
    return 0;
}
