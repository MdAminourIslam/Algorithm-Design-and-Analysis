#include <iostream>
#include <vector>
using namespace std;

void backtrack(int n, int k, int start, vector<int>& curr, vector<vector<int>>& result) {
    if (curr.size() == k) {
        result.push_back(curr);
        return;
    }
    for (int i = start; i <= n; i++) {
        curr.push_back(i);
        backtrack(n, k, i + 1, curr, result);
        curr.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> curr;
    backtrack(n, k, 1, curr, result);
    return result;
}

int main() {
    vector<vector<int>> result = combine(4, 2);
    cout << "Combinations of 4 choose 2:\n";
    for (auto& comb : result) {
        for (int v : comb) cout << v << " ";
        cout << "\n";
    }
    return 0;
}
