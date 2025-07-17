#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Corrected sorting syntax
        
        for(int i = 0; i < nums.size(); i++) {
            if(i != nums[i]) return i;  // If index does not match value, return index
        }

        return nums.size();  // If all numbers match their indices, return the last number
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 0, 1};
    cout << "Missing number: " << solution.missingNumber(nums) << endl;
    return 0;
}
