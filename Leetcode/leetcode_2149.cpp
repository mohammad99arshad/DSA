#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> s1;
        vector<int> s2;
        vector<int> ans(nums.size());

        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                s1.push_back(nums[i]);
            } else {
                s2.push_back(nums[i]);
            }
        }

        int j = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i % 2 == 0) {
                ans[i] = s1[j];
            } else {
                ans[i] = s2[j];
                j++;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, -1, 2, -2, 3, -3, 4, -4};
    
    vector<int> result = sol.rearrangeArray(nums);
    
    cout << "Rearranged Array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
