#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> zFunction(string s) {
    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] - 1 > r) { l = i; r = i + z[i] - 1; }
    }
    return z;
}

int patternMatch(string text, string pattern) {
    string concat = pattern + "$" + text;
    vector<int> z = zFunction(concat);
    int count = 0;
    for (int i = pattern.size() + 1; i < concat.size(); i++)
        if (z[i] == pattern.size()) count++;
    return count;
}

int main() {
    string text = "abcabcabc";
    string pattern = "abc";
    cout << "Pattern '" << pattern << "' found " << patternMatch(text, pattern) << " times\n";
    return 0;
}
