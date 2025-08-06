// Check if there exists a subsequence with sum K

#include<bits/stdc++.h>
using namespace std;

bool checkSum(int pos,int sum, vector<int>&nums, int k){
    if(sum == k) return true;
    
    if(pos == nums.size()) return false;

    if(checkSum(pos+1, nums[pos]+sum, nums, k)) return true;

    if(checkSum(pos+1, sum, nums, k)) return true;

    return false;
}

bool checkSubsequenceSum(vector<int>& nums, int k) {
    return checkSum(0,0,nums, k);
}
int main(){
    vector<int>nums = {1,2,3,5,6,4,8,9};
    int k = 8;

    if(checkSubsequenceSum(nums, k)){
        cout<<"True"<<endl;
    }else{
        cout<<"false"<<endl;
    }
}