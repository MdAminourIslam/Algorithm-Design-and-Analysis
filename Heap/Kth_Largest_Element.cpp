#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int num : nums) {
        minHeap.push(num);
        if (minHeap.size() > k) minHeap.pop();
    }
    return minHeap.top();
}

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    cout << k << "nd largest: " << findKthLargest(nums, k) << "\n";
    nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    k = 4;
    cout << k << "th largest: " << findKthLargest(nums, k) << "\n";
    return 0;
}
