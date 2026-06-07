#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class MedianFinder {
    priority_queue<int> maxHeap; // left half
    priority_queue<int, vector<int>, greater<int>> minHeap; // right half
public:
    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) maxHeap.push(num);
        else minHeap.push(num);
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top()); maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top()); minHeap.pop();
        }
    }
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) return maxHeap.top();
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

int main() {
    MedianFinder mf;
    vector<int> stream = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int num : stream) {
        mf.addNum(num);
        cout << "Added " << num << ", Median: " << mf.findMedian() << "\n";
    }
    return 0;
}
