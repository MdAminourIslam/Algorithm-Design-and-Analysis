#include <bits/stdc++.h>
using namespace std;

void bellmanFord(int nodes, int edges, vector<vector<int>>& edgeList, int source) {
    vector<int> dist(nodes + 1, INT_MAX); // Distance array initialized to infinity
    dist[source] = 0; // Distance to the source is 0

    // Relax all edges (nodes - 1) times
    for(int i = 1; i <= nodes - 1; ++i) {
        for(int j = 0; j < edges; ++j) {
            int u = edgeList[j][0]; // Start node of the edge
            int v = edgeList[j][1]; // End node of the edge
            int weight = edgeList[j][2]; // Weight of the edge
            if(dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative weight cycles
    for(int j = 0; j < edges; ++j) {
        int u = edgeList[j][0];
        int v = edgeList[j][1];
        int weight = edgeList[j][2];
        if(dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains a negative weight cycle" << endl;
            return;
        }
    }

    // Print shortest distances
    for(int i = 1; i <= nodes; ++i) {
        if(dist[i] == INT_MAX) {
            cout << "INF ";
        } else {
            cout << dist[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    vector<vector<int>> edgeList(edges, vector<int>(3));

    // Input the edges
    for(int i = 0; i < edges; ++i) {
        cin >> edgeList[i][0] >> edgeList[i][1] >> edgeList[i][2];
    }

    int source;
    cin >> source;

    bellmanFord(nodes, edges, edgeList, source);

    return 0;
}

