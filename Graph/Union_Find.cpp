#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
    vector<int> parent, rank;
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (rank[px] < rank[py]) parent[px] = py;
        else if (rank[px] > rank[py]) parent[py] = px;
        else { parent[py] = px; rank[px]++; }
    }
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    UnionFind uf(7);
    uf.unite(0, 1); uf.unite(1, 2);
    uf.unite(3, 4); uf.unite(4, 5);
    cout << "0 and 2 connected: " << uf.connected(0, 2) << "\n";
    cout << "0 and 3 connected: " << uf.connected(0, 3) << "\n";
    uf.unite(2, 3);
    cout << "After union, 0 and 3 connected: " << uf.connected(0, 3) << "\n";
    return 0;
}
