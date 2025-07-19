// kth closest number

#include<bits/stdc++.h>
using namespace std;

vector<int> kthcloset(vector<int>nums, int k, int x){
    priority_queue<pair<int, int>>maxheap;
    for(int i=0; i<nums.size(); i++){
        maxheap.push({abs(nums[i]-x), nums[i]});
        if(maxheap.size() > k){
            maxheap.pop();
        }
    }
    vector<int>result;
    while(!maxheap.empty()){
        cout<<maxheap.top().second<<" ";
        maxheap.pop();
    }
    return result;
}

int main(){
    vector<int>arr = {5,6,7,8,9};
    int k = 3;
    int x = 7;
    vector<int>result = kthcloset(arr, k, x);
    for(int num : result){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}