#include <iostream>
#include <vector>
using namespace std;

// Function to check if it's safe to assign color `c` to vertex `v`
bool isSafe(int v, vector<vector<int>>& graph, vector<int>& color, int c) {
    for (int i = 0; i < graph.size(); i++) {
        if (graph[v][i] == 1 && color[i] == c) {
            return false;
        }
    }
    return true;
}

// Recursive function to solve the graph coloring problem
bool graphColoringUtil(vector<vector<int>>& graph, int m, vector<int>& color, int v) {
    if (v == graph.size()) {
        return true; // All vertices are colored
    }

    // Try different colors for vertex `v`
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c; // Assign color `c`

            // Recur to assign colors to the rest of the vertices
            if (graphColoringUtil(graph, m, color, v + 1)) {
                return true;
            }

            color[v] = 0; // Backtrack
        }
    }

    return false; // If no color can be assigned
}

// Function to solve the m-coloring problem
bool graphColoring(vector<vector<int>>& graph, int m) {
    int V = graph.size();
    vector<int> color(V, 0);

    if (!graphColoringUtil(graph, m, color, 0)) {
        cout << "Solution does not exist with " << m << " colors." << endl;
        return false;
    }

    // Print the assigned colors
    cout << "Solution exists with " << m << " colors:" << endl;
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << " ---> Color " << color[i] << endl;
    }

    return true;
}

// Main function
int main() {
    // Number of vertices
    int V = 4;

    // Adjacency matrix representation of the graph
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int m = 3; // Number of colors
    graphColoring(graph, m);

    return 0;
}

