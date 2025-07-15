#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;

            // Ensure mid is even for correct pairing
            if (mid % 2 == 1) mid--;

            if (nums[mid] == nums[mid + 1]) {
                low = mid + 2; // Move right
            } else {
                high = mid; // Move left
            }
        }
        return nums[low]; // The single element
    }
};

// Example usage:
int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4};
    cout << sol.singleNonDuplicate(nums); // Output: 4
    return 0;
}
