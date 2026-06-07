#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string longestPalindromicSubstring(string s) {
    string t = "$#";
    for (char c : s) { t += c; t += '#'; }
    t += '@';
    int n = t.size();
    vector<int> p(n, 0);
    int center = 0, right = 0, maxLen = 0, maxCenter = 0;
    for (int i = 1; i < n - 1; i++) {
        if (i < right) p[i] = min(right - i, p[2 * center - i]);
        while (t[i + p[i] + 1] == t[i - p[i] - 1]) p[i]++;
        if (i + p[i] > right) { center = i; right = i + p[i]; }
        if (p[i] > maxLen) { maxLen = p[i]; maxCenter = i; }
    }
    int start = (maxCenter - maxLen) / 2;
    return s.substr(start, maxLen);
}

int main() {
    string s = "babad";
    cout << "Longest palindromic substring of '" << s << "': " << longestPalindromicSubstring(s) << "\n";
    s = "cbbd";
    cout << "Longest palindromic substring of '" << s << "': " << longestPalindromicSubstring(s) << "\n";
    s = "racecar";
    cout << "Longest palindromic substring of '" << s << "': " << longestPalindromicSubstring(s) << "\n";
    return 0;
}
