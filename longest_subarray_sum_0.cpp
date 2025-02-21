#include <bits/stdc++.h>
using namespace std;

int getLongestZeroSumSubarrayLength(vector<int> &arr) {
    int n = arr.size();
    int maxlen = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == 0) {
                maxlen = max(maxlen, j - i + 1);
            }
        }
    }
    return maxlen;
}

int main() {
    vector<int> arr = {1, 2, -3, 3, 1, -4, 2, 2, -2, -2}; // Example input
    int result = getLongestZeroSumSubarrayLength(arr);
    cout << "Longest zero-sum subarray length: " << result << endl;
    return 0;
}
