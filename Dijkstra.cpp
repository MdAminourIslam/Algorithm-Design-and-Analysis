#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int inf = 1e15;

vector<vector<pii>> adj; // Adjacency list
vector<int> dist;        // Distance array

void dijkstra(int source, int n) {
    vector<bool> visited(n + 1, false); // Visited array
    priority_queue<pii, vector<pii>, greater<pii>> pq; // Min-heap

    pq.push({0, source});
    dist[source] = 0;

    while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int u = it.second;

        if(visited[u]) continue;
        visited[u] = true;

        for(auto x : adj[u]) {
            int v = x.second;
            int weight = x.first;

            if(dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    for(int i = 1; i <= n; ++i) {
       cout << dist[i] << " ";
    }
    cout << endl;
}

signed main() {
    int node, edge;
    cin >> node >> edge;

    adj.resize(node + 1);
    dist.assign(node + 1, inf);

    for (int i = 0; i < edge; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
       // adj[v].push_back({w, u});
    }

    dijkstra(1, node);

    return 0;
}
