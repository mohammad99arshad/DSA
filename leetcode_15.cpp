#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); // Sorting for two-pointer approach

        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            // Avoid duplicate triplets
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1, right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Avoid duplicate values
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return result;
    }
};

// Driver code to test the function
int main() {
    Solution sol;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> triplets = sol.threeSum(nums);

    cout << "Triplets that sum to zero:\n";
    for (const auto& triplet : triplets) {
        cout << "[";
        for (int i = 0; i < triplet.size(); i++) {
            cout << triplet[i] << (i == triplet.size() - 1 ? "" : ", ");
        }
        cout << "]\n";
    }

    return 0;
}
