#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> seen;  // Stores last k elements

        for (int i = 0; i < nums.size(); i++) {
            // Step 1: Check if nums[i] already exists in the set
            if (seen.find(nums[i]) != seen.end()) {
                return true; // Found a duplicate within k range
            }

            // Step 2: Insert nums[i] into the set
            seen.insert(nums[i]);

            // Step 3: Maintain only the last k elements
            if (seen.size() > k) {
                seen.erase(nums[i - k]); // Remove the oldest element
            }
        }

        return false; // No duplicates found within k distance
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};  // Example input
    int k = 3;

    // Call the function and print the result
    if (sol.containsNearbyDuplicate(nums, k)) {
        cout << "true" << endl;  // Expected output: true
    } else {
        cout << "false" << endl;
    }

    return 0;
}
