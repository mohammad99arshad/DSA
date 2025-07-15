#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end());

        while (low <= high) {
            int mid = low + (high - low) / 2; // Avoid overflow
            if (sumByD(nums, mid) <= threshold) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low; // The smallest divisor
    }

private:
    int sumByD(vector<int>& arr, int div) {
        int sum = 0;
        for (int num : arr) {
            sum += (num + div - 1) / div; // Equivalent to ceil(num / div)
        }
        return sum;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;

    cout << "Smallest Divisor: " << sol.smallestDivisor(nums, threshold) << endl;
    return 0;
}
