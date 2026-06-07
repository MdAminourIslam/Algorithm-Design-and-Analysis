#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

void dfs1(vector<vector<int>>& adj, int u, vector<bool>& visited, stack<int>& st) {
    visited[u] = true;
    for (int v : adj[u])
        if (!visited[v]) dfs1(adj, v, visited, st);
    st.push(u);
}

void dfs2(vector<vector<int>>& radj, int u, vector<bool>& visited, vector<int>& comp) {
    visited[u] = true;
    comp.push_back(u);
    for (int v : radj[u])
        if (!visited[v]) dfs2(radj, v, visited, comp);
}

vector<vector<int>> kosaraju(vector<vector<int>>& adj, int n) {
    stack<int> st;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
        if (!visited[i]) dfs1(adj, i, visited, st);
    vector<vector<int>> radj(n);
    for (int u = 0; u < n; u++)
        for (int v : adj[u]) radj[v].push_back(u);
    fill(visited.begin(), visited.end(), false);
    vector<vector<int>> sccs;
    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (!visited[u]) {
            vector<int> comp;
            dfs2(radj, u, visited, comp);
            sccs.push_back(comp);
        }
    }
    return sccs;
}

int main() {
    int n = 5;
    vector<vector<int>> adj(n);
    adj[0] = {2, 3}; adj[1] = {0};
    adj[2] = {1}; adj[3] = {4};
    vector<vector<int>> sccs = kosaraju(adj, n);
    cout << "SCCs:\n";
    for (auto& comp : sccs) {
        for (int v : comp) cout << v << " ";
        cout << "\n";
    }
    return 0;
}
