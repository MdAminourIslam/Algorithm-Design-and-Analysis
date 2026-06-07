#include <iostream>
#include <vector>
using namespace std;

bool dfsDirected(vector<vector<int>>& adj, int u, vector<int>& visited) {
    visited[u] = 1;
    for (int v : adj[u]) {
        if (visited[v] == 1) return true;
        if (visited[v] == 0 && dfsDirected(adj, v, visited)) return true;
    }
    visited[u] = 2;
    return false;
}

bool hasCycleDirected(vector<vector<int>>& adj, int n) {
    vector<int> visited(n, 0);
    for (int i = 0; i < n; i++)
        if (visited[i] == 0 && dfsDirected(adj, i, visited)) return true;
    return false;
}

bool dfsUndirected(vector<vector<int>>& adj, int u, int parent, vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            if (dfsUndirected(adj, v, u, visited)) return true;
        } else if (v != parent) return true;
    }
    return false;
}

bool hasCycleUndirected(vector<vector<int>>& adj, int n) {
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
        if (!visited[i] && dfsUndirected(adj, i, -1, visited)) return true;
    return false;
}

int main() {
    int n = 4;
    vector<vector<int>> adjDir(n), adjUnDir(n);
    adjDir[0] = {1}; adjDir[1] = {2}; adjDir[2] = {0}; adjDir[2] = {3};
    adjUnDir[0] = {1, 2}; adjUnDir[1] = {0, 2}; adjUnDir[2] = {0, 1};
    cout << "Directed graph has cycle: " << hasCycleDirected(adjDir, n) << "\n";
    cout << "Undirected graph has cycle: " << hasCycleUndirected(adjUnDir, n) << "\n";
    return 0;
}
