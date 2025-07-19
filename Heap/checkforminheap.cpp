#include <bits/stdc++.h>
using namespace std;

bool isHeap(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i <= (n - 2) / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && nums[i] > nums[left]) return false;
        if (right < n && nums[i] > nums[right]) return false;
    }
    return true;
}

int main() {
    vector<int> arr = {2, 3, 5, 6, 8, 9};
    if (isHeap(arr))
        cout << "The array represents a min-heap.\n";
    else
        cout << "The array does NOT represent a min-heap.\n";
    return 0;
}
