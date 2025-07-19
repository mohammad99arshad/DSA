#include<bits/stdc++.h>
using namespace std;

int connectRopes(vector<int>& nums){
    priority_queue<int, vector<int>, greater<int>>minheap;
    
    for(int i=0; i<nums.size(); i++){
        minheap.push(nums[i]);
    }
    int tCost = 0;
    while(minheap.size() >= 2){
        int first = minheap.top();
        minheap.pop();
        int second = minheap.top();
        minheap.pop();
        tCost += first + second;
        minheap.push(first+second);
    }
    return tCost;
}

int main(){
    vector<int>arr = {1,2,3,4,5};
    int result = connectRopes(arr);
    cout<<result<<endl;
    return 0;
}