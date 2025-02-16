#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        int n = arr.size();

        // Step 1: Sort the array (O(N log N))
        sort(arr.begin(), arr.end());

        // Step 2: Find the minimum absolute difference (O(N))
        int minDiff = INT8_MAX;
        for (int i = 0; i < n - 1; i++) {
            minDiff = min(minDiff, arr[i + 1] - arr[i]);
        }

        // Step 3: Collect pairs with the minimum difference (O(N))
        for (int i = 0; i < n - 1; i++) {
            if (arr[i + 1] - arr[i] == minDiff) {
                ans.push_back({arr[i], arr[i + 1]});
            }
        }

        return ans;
    }
};

// ✅ **Main function to test the solution**
int main() {
    Solution sol;
    vector<int> arr = {4, 2, 1, 3};

    vector<vector<int>> result = sol.minimumAbsDifference(arr);

    // Print result
    for (auto &pair : result) {
        cout << "[" << pair[0] << ", " << pair[1] << "] ";
    }
    cout << endl;

    return 0;
}
