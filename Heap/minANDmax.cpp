#include <bits/stdc++.h>
using namespace std;

int main() {
    // Max Heap (default behavior of priority_queue)
    priority_queue<int> maxHeap;

    // Min Heap (requires comparator)
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Sample input
    vector<int> arr = {10, 5, 20, 2, 8, 15};

    // Insert into both heaps
    for (int num : arr) {
        maxHeap.push(num);
        minHeap.push(num);
    }

    // Print Max Heap elements (in descending order)
    cout << "Max Heap: ";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    cout << endl;

    // Print Min Heap elements (in ascending order)
    cout << "Min Heap: ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;

    return 0;
}
