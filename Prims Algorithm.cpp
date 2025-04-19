#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

void primMST(vector<vector<pair<int, int>>>& graph, int V) {
    // Priority queue to store {weight, {u, v}}
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    vector<bool> visited(V, false); // To track visited vertices
    vector<pair<int, int>> mst;     // To store the MST edges

    // Start from vertex 0, weight is 0
    pq.push({0, {0, -1}}); // {weight, {vertex, parent}}

    int mstCost = 0;

    while (!pq.empty()) {
        auto [weight, edge] = pq.top();
        pq.pop();

        int u = edge.first;
        int parent = edge.second;

        if (visited[u]) continue;

        visited[u] = true; // Mark the vertex as visited
        mstCost += weight;

        if (parent != -1) {
            mst.push_back({parent, u}); // Add edge to MST
        }

        // Explore adjacent vertices
        for (auto [v, w] : graph[u]) {
            if (!visited[v]) {
                pq.push({w, {v, u}}); // Push edge {weight, {to_vertex, from_vertex}}
            }
        }
    }

    // Print the MST
    cout << "Minimum Spanning Tree Cost: " << mstCost << endl;
    cout << "Edges in MST:\n";
    for (auto [u, v] : mst) {
        cout << u << " - " << v << endl;
    }
}

int main() {
    int V = 5;
    vector<vector<pair<int, int>>> graph(V);

    // Add edges {to, weight}
    graph[0].push_back({1, 2});
    graph[1].push_back({0, 2});

    graph[0].push_back({3, 6});
    graph[3].push_back({0, 6});

    graph[1].push_back({2, 3});
    graph[2].push_back({1, 3});

    graph[1].push_back({3, 8});
    graph[3].push_back({1, 8});

    graph[1].push_back({4, 5});
    graph[4].push_back({1, 5});

    graph[2].push_back({4, 7});
    graph[4].push_back({2, 7});

    cout << "Prim's Algorithm using Priority Queue:\n";
    primMST(graph, V);

    return 0;
}

