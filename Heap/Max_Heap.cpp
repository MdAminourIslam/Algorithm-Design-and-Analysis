#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MaxHeap {
    vector<int> heap;
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    void heapifyDown(int i) {
        int l = left(i), r = right(i), largest = i;
        if (l < heap.size() && heap[l] > heap[largest]) largest = l;
        if (r < heap.size() && heap[r] > heap[largest]) largest = r;
        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }
    void heapifyUp(int i) {
        while (i && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
public:
    void push(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }
    int pop() {
        if (heap.empty()) return -1;
        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return root;
    }
    int top() { return heap.empty() ? -1 : heap[0]; }
    bool empty() { return heap.empty(); }
};

int main() {
    MaxHeap maxHeap;
    maxHeap.push(10); maxHeap.push(5); maxHeap.push(15);
    maxHeap.push(3); maxHeap.push(7);
    cout << "Max Heap elements: ";
    while (!maxHeap.empty()) cout << maxHeap.pop() << " ";
    cout << "\n";
    return 0;
}
