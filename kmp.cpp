#include<bits/stdc++.h>
using namespace std;

vector<int> buildLPS(string &s) {
    vector<int> lps(s.size(), 0);
    int index = 0, i = 1;
    while(i < s.size()) {
        if(s[i] == s[index]) {
            lps[i] = index + 1;
            i++, index++;
        } else {
            if(index != 0) {
                index = lps[index - 1];
            } else {
                lps[i] = 0, i++;
            }
        }
    }
    return lps;
}

vector<int> KMP(string &pattern, string &text) {
    vector<int> lps = buildLPS(pattern);
    vector<int> found;
    int i = 0, j = 0;
    while(i < text.size()) {
        if(pattern[j] == text[i]) {
            i++, j++;
        } else {
            if(j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
        if(j == pattern.size()) {
            found.push_back(i - pattern.size());
            j = lps[j - 1];
        }
    }
    return found;
}

int main() {
    string text = "aabaacaadaabaaba";
    string pattern = "aaba";

    vector<int> matches = KMP(pattern, text);
    if(matches.empty()) {
        cout << "Pattern does not match!" << "\n";
    } else {
        cout << "Pattern found at indices: ";
        for(int idx : matches) {
           cout << idx << " ";
        }
    }
    return 0;
}

