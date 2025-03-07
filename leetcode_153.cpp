#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            // If mid element is greater than the last element, min is in the right half
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else { // Min is in the left half (including mid)
                high = mid;
            }
        }
        
        return nums[low]; // `low` will point to the minimum element
    }
};

// Example usage:
int main() {
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << sol.findMin(nums); // Output: 0
    return 0;
}
