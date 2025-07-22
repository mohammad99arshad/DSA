//leetcode 55 

#include<bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {
    int index = 0;
    for(int i=0; i<nums.size(); i++){
        if(i > index) return false;
        index = max(index, i+nums[i]);
    }
    return true;        
}

int main(){
    vector<int> arr = {2,3,1,0,4};
    bool result = canJump(arr);
    cout<<result<<endl;
    return 0;
}