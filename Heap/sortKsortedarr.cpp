#include <bits/stdc++.h>
using namespace std;

vector<int> kthsorted(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minheap;
    vector<int> result;
    int n = nums.size();

    // Step 1: Push first k+1 elements into the heap
    for (int i = 0; i <= k; i++) {
        minheap.push(nums[i]);
    }

    // Step 2: Process remaining elements
    for (int i = k + 1; i < n; i++) {
        result.push_back(minheap.top());
        minheap.pop();
        minheap.push(nums[i]);
    }

    // Step 3: Pop remaining elements from heap
    while (!minheap.empty()) {
        result.push_back(minheap.top());
        minheap.pop();
    }

    return result;
}

int main() {
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;

    vector<int> result = kthsorted(arr, k);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
