#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int left = 0, right = 0;
    int count = 0;
    int maxlen = 0;
    
    while (right < nums.size()) {
        if (nums[right] == 0) count++;

        while (count > k) {
            if (nums[left] == 0) count--;
            left++;
        }

        maxlen = max(maxlen, right - left + 1);
        right++;
    }

    return maxlen;
}

int main() {
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    cout << longestOnes(nums, k) << endl;
    return 0;
}
