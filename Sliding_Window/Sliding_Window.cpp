#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

// Maximum sum subarray of size k
int maxSumSubarray(vector<int>& arr, int k) {
    int maxSum = 0, windowSum = 0;
    for (int i = 0; i < k; i++) windowSum += arr[i];
    maxSum = windowSum;
    for (int i = k; i < arr.size(); i++) {
        windowSum += arr[i] - arr[i - k];
        maxSum = max(maxSum, windowSum);
    }
    return maxSum;
}

// Longest substring without repeating characters
int longestUniqueSubstr(string s) {
    unordered_map<char, int> lastIndex;
    int maxLen = 0, left = 0;
    for (int right = 0; right < s.size(); right++) {
        if (lastIndex.find(s[right]) != lastIndex.end())
            left = max(left, lastIndex[s[right]] + 1);
        lastIndex[s[right]] = right;
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

int main() {
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;
    cout << "Max sum subarray of size " << k << ": " << maxSumSubarray(arr, k) << "\n";
    string s = "abcabcbb";
    cout << "Longest unique substring: " << longestUniqueSubstr(s) << "\n";
    return 0;
}
