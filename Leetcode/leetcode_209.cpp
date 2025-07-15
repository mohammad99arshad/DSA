#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, sum = 0, minLength = INT_MAX;
        int n = nums.size();

        for (int right = 0; right < n; right++) {
            sum += nums[right];

            // Shrink the window while sum is at least the target
            while (sum >= target) {
                minLength = min(minLength, right - left + 1);
                sum -= nums[left]; // Remove leftmost element
                left++; // Move left pointer
            }
        }

        return (minLength == INT_MAX) ? 0 : minLength;
    }
};

// ✅ **Main function to test the solution**
int main() {
    Solution sol;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;

    cout << "Minimum subarray length: " << sol.minSubArrayLen(target, nums) << endl;
    return 0;
}
