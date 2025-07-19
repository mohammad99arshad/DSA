#include <bits/stdc++.h>
using namespace std;

class PriorityQueue {
private:
    vector<pair<int, int>> heap; // {priority, value}

    int getIndex(int value) {
        for (int i = 0; i < heap.size(); i++) {
            if (heap[i].second == value) return i;
        }
        return -1;
    }

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent].first > heap[index].first) {
                swap(heap[parent], heap[index]);
                index = parent;
            } else break;
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (index < size) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < size && heap[left].first < heap[smallest].first)
                smallest = left;
            if (right < size && heap[right].first < heap[smallest].first)
                smallest = right;

            if (smallest != index) {
                swap(heap[index], heap[smallest]);
                index = smallest;
            } else break;
        }
    }

public:
    void insert(int priority, int value) {
        heap.push_back({priority, value});
        heapifyUp(heap.size() - 1);
    }

    pair<int, int> peek() {
        if (!heap.empty()) return heap[0];
        return {-1, -1}; // Empty
    }

    pair<int, int> extractMin() {
        if (heap.empty()) return {-1, -1};
        pair<int, int> minElement = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return minElement;
    }

    void changePriority(int value, int newPriority) {
        int index = getIndex(value);
        if (index == -1) {
            cout << "Value not found!\n";
            return;
        }
        int oldPriority = heap[index].first;
        heap[index].first = newPriority;
        if (newPriority < oldPriority)
            heapifyUp(index);
        else
            heapifyDown(index);
    }

    bool isEmpty() {
        return heap.empty();
    }

    void display() {
        for (auto p : heap)
            cout << "(" << p.second << ", p=" << p.first << ") ";
        cout << "\n";
    }
};

int main() {
    PriorityQueue pq;

    pq.insert(3, 100);
    pq.insert(1, 200);
    pq.insert(4, 300);
    pq.insert(2, 400);

    cout << "Queue: ";
    pq.display();

    cout << "Top: " << pq.peek().second << "\n";

    pq.changePriority(300, 0);
    cout << "After changing priority of 300:\n";
    pq.display();

    cout << "Extracted: " << pq.extractMin().second << "\n";
    cout << "Queue after extraction: ";
    pq.display();

    cout << (pq.isEmpty() ? "Empty" : "Not Empty") << "\n";

    return 0;
}
