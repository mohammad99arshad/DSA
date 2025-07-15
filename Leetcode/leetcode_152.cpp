#include <bits/stdc++.h>
using namespace std;

int maxProductSubArray(vector<int>& nums) {
    int result = nums[0];
    int n = nums.size();
    
    for (int i = 0; i < n; i++) {
        int p = 1;  // Initialize product to 1
        for (int j = i; j < n; j++) {
            p *= nums[j];
            result = max(result, p);
        }
    }
    return result;
}

int main() {
    vector<int> nums = {-2, 0, -1};
    cout << maxProductSubArray(nums) << endl;  // Output: 0
    return 0;
}
