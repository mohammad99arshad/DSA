#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int>& nums, int k) {
    unordered_map<int, int> prefixSumMap; // Stores (prefix sum, first index)
    int sum = 0, maxlen = 0;

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];

        if (sum == k) 
            maxlen = i + 1;  // If prefix sum itself is equal to k, update maxlen

        if (prefixSumMap.find(sum - k) != prefixSumMap.end()) 
            maxlen = max(maxlen, i - prefixSumMap[sum - k]);

        if (prefixSumMap.find(sum) == prefixSumMap.end()) 
            prefixSumMap[sum] = i;  // Store the first occurrence of the prefix sum
    }
    return maxlen;
}

int main() {
    int t;
    cin >> t;  // Number of test cases
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        cout << getLongestSubarray(nums, k) << endl;
    }
    return 0;
}
