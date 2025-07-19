#include<bits/stdc++.h>
using namespace std;

int sumofElement(vector<int>nums, int k){
    priority_queue<int>maxheap;
    for(int i=0; i<nums.size(); i++){
        maxheap.push(nums[i]);
        if(maxheap.size() > k){
            maxheap.pop();
        }
    }
    return maxheap.top();
}

int main(){
    vector<int>arr = {2,3,5,7,8,10,12};
    int first = sumofElement(arr, 3);
    int second = sumofElement(arr, 6);
    int sum = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i]>first && arr[i] < second){
            sum += arr[i];
        }
    }
    cout<<sum<<endl;
}