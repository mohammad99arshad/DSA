#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        
        // Compare each element with every other element
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (nums[j] < nums[i]) {
                    result[i]++;
                }
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {8, 1, 2, 2, 3};
    
    vector<int> result = sol.smallerNumbersThanCurrent(nums);
    
    cout << "Output: ";
    for (int num : result) {
        cout << num << " ";
    }
    
    return 0;
}
