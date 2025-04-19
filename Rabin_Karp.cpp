#include<bits/stdc++.h>
using namespace std;
const int Mod = 1e9 + 7;
int main() {
    string s;
    cout << "Enter Original Text : ";
    cin >> s;
    string pattern;
    cout << "Enter Pattern Text : ";
    cin >> pattern;

    int prime = 3;
    if(s.size() < pattern.size()) {
        cout << "Original string size must not be less than pattern size!\n";
        return 0;
    }
    int w = pattern.size();
    int hash_of_pattern = 0, power = 1;
    for(int i = 0; i < w; i++) {
        int value = pattern[i] - 'a' + 1;
        hash_of_pattern += value * power;
        power *= prime;
    }

    int old_hash = 0;
    power = 1;
    for(int i = 0; i < w; i++) {
        int value = s[i] - 'a' + 1;
        old_hash += value * power;
        power *= prime;
    }

    if(hash_of_pattern == old_hash) {
        cout << "Pattern Match!" << "\n";
        return 0;
    }
    power /= prime;
    for(int i = w; i < s.size(); i++) {
        int x = old_hash - (s[i - w] - 'a' + 1);
        x /= prime;
        x += (s[i] - 'a' + 1) * power;
        if(x == hash_of_pattern) {
           cout << "Pattern Match!" << "\n";
           return 0;
        }
        old_hash = x;
    }
    cout << "Patter does not match!\n";
    return 0;
}




