// a contiguous or non contiguous sequence which follows order

#include<bits/stdc++.h>
using namespace std;

void genSub(int pos, vector<int>&nums, vector<int>&sub, vector<vector<int>>&res){
    res.push_back(sub);
    for(int i=pos; i<nums.size(); i++){
        sub.push_back(nums[i]);
        genSub(i+1, nums, sub, res);
        sub.pop_back();
    }
}

vector<vector<int>>subsett(vector<int>& nums){
    vector<vector<int>>res;
    vector<int>sub;
    genSub(0, nums, sub, res);
    return res;
}
int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = subsett(nums);

    for (const auto& subset : res) {
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
