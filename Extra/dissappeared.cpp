#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();

        // Mark visited indices by negating numbers
        for (int i = 0; i < n; i++) {
            int index = abs(nums[i]) - 1;  // Get correct index
            if (nums[index] > 0) nums[index] = -nums[index]; // Mark as visited
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) result.push_back(i + 1);  // Collect missing numbers
        }

        return result;
    }
};
int main(){
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};  // Example input
    Solution sol;
    vector<int> missingNumbers = sol.findDisappearedNumbers(nums);

    cout << "Missing Numbers: ";
    for (int num : missingNumbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}