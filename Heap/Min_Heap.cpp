#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MinHeap {
    vector<int> heap;
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    void heapifyDown(int i) {
        int l = left(i), r = right(i), smallest = i;
        if (l < heap.size() && heap[l] < heap[smallest]) smallest = l;
        if (r < heap.size() && heap[r] < heap[smallest]) smallest = r;
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }
    void heapifyUp(int i) {
        while (i && heap[parent(i)] > heap[i]) {
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
    MinHeap minHeap;
    minHeap.push(10); minHeap.push(5); minHeap.push(15);
    minHeap.push(3); minHeap.push(7);
    cout << "Min Heap elements: ";
    while (!minHeap.empty()) cout << minHeap.pop() << " ";
    cout << "\n";
    return 0;
}
