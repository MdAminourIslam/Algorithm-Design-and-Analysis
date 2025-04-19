#include <bits/stdc++.h>
using namespace std;

#define INF 1e9 // Representing infinity for unreachable nodes

void floydWarshall(int n, vector<vector<int>>& graph) {
    vector<vector<int>> dist = graph; // Initialize distance matrix with graph weights

    // Floyd-Warshall algorithm
    for(int k = 0; k < n; ++k) { // Intermediate vertex
        for (int i = 0; i < n; ++i) { // Source vertex
            for (int j = 0; j < n; ++j) { // Destination vertex
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Check for negative weight cycles
    for(int i = 0; i < n; ++i) {
        if (dist[i][i] < 0) {
            cout << "Graph contains a negative weight cycle." << endl;
            return;
        }
    }

    // Print shortest distances
    cout << "Shortest distances between every pair of vertices:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INF) cout << "INF ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m; // Number of vertices and edges

    vector<vector<int>> graph(n, vector<int>(n, INF)); // Initialize graph with INF
    for(int i = 0; i < n; ++i) graph[i][i] = 0; // Distance to self is 0

    for(int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w; // Edge from u to v with weight w
        graph[u][v] = w;
    }

    floydWarshall(n, graph);

    return 0;
}

