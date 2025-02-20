#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int mini = n / 3;  // No need for +1
        vector<int> ls;
        map<int, int> mpp;

        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;  // Fix: Correctly increment the count

            if (mpp[nums[i]] == mini + 1) {  // Fix: Ensure unique insertion
                ls.push_back(nums[i]);
            }
        }

        return ls;
    }
};

int main() {
    vector<int> nums = {3, 2, 3};
    Solution sol;
    vector<int> result = sol.majorityElement(nums);

    cout << "Majority Elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
