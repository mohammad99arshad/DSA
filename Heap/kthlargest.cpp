#include <bits/stdc++.h>
using namespace std;

vector<int> kLargestElements(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minheap;

    for (int num : nums) {
        minheap.push(num);
        if (minheap.size() > k) {
            minheap.pop();
        }
    }

    vector<int> result;
    while (!minheap.empty()) {
        result.push_back(minheap.top());
        minheap.pop();
    }

    // Optional: sort in descending order if needed
    // sort(result.rbegin(), result.rend());

    return result;
}

int main() {
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;

    vector<int> result = kLargestElements(arr, k);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
