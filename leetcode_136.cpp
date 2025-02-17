#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int x = 0;  // Variable to store the result using XOR
        for(int i = 0; i < n; i++) {
            x ^= nums[i];  // XOR each element in the array
        }
        return x;
    }
};

// Example usage
#include <iostream>

int main() {
    vector<int> nums = {4, 1, 2, 1, 2};
    Solution sol;
    cout << "Single number: " << sol.singleNumber(nums) << endl;
    return 0;
}
