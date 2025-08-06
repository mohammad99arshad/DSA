#include<bits/stdc++.h>
using namespace std;

void backtrack(int pos, vector<int>&nums, vector<int>&curr, vector<vector<int>>&res){
    res.push_back(curr);
    for(int i=pos; i<nums.size(); i++){
        if(i > pos && nums[i] == nums[i-1]) continue;
        curr.push_back(nums[i]);
        backtrack(i+1, nums, curr, res);
        curr.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>>res;
    vector<int>sub;
    backtrack(0, nums, sub, res);
    return res;
}

int main(){
    vector<int> arr{3, 2, 1};
    vector<vector<int>> res = subsetsWithDup(arr);
    for(const auto& subset : res){
        cout << "[";
        for(int num : subset){
            cout << num << " ";
        }
        cout << "]";
    }
    cout << endl;
    return 0;
}
