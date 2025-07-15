#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int xorr = 0;
    for(int i = 0; i < nums.size(); i++) {
        xorr ^= nums[i];  // same as xorr = xorr ^ nums[i];
    }
    return xorr;
}

int main() {
    vector<int> arr = {4, 2, 1, 2, 1};  
    cout << singleNumber(arr) << endl;
    return 0;
}
