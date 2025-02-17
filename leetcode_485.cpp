#include <iostream>
#include <vector>
#include <algorithm>  // For max function

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxlen = 0;
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) {
                count++;
                maxlen = max(maxlen, count);
            } else {
                count = 0;
            }
        }
        return maxlen;
    }
};

// Example usage
int main() {
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    Solution sol;
    cout << "Maximum consecutive ones: " << sol.findMaxConsecutiveOnes(nums) << endl;
    return 0;
}
