// kth smallest element fromthe array

#include<bits/stdc++.h>
using namespace std;

int kthSmallest(vector<int>& nums, int k){
    priority_queue<int>maxheap;
    int n = nums.size();
    for(int i=0; i<n; i++){
        maxheap.push(nums[i]);
        if(maxheap.size() > k){
            maxheap.pop();
        }
    }
    return maxheap.top();
}

int main(){
    vector<int> arr = {7,10,4,3,20,15};
    int n = 3;
    int result = kthSmallest(arr, n);
    cout<<result<<endl;
    return 0;
}