#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans = "";
        for (int i = 0; i < nums.size(); i++) {
            ans += (nums[i][i] == '0') ? '1' : '0';  // Flipping the diagonal element
        }
        return ans;
    }
};

int main() {
    vector<string> nums = {"000", "111", "101"};
    Solution sol;
    string result = sol.findDifferentBinaryString(nums);
    cout << "Unique Binary String: " << result << endl;
    return 0;
}
