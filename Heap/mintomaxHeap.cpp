#include<bits/stdc++.h>
using namespace std;

vector<int> minTomax(vector<int>& nums) {
    vector<int> maxHeap = nums;
    make_heap(maxHeap.begin(), maxHeap.end());  
    return maxHeap;
}

int main(){
    vector<int>arr = {10,20,30,21,23};
    vector<int>result = minTomax(arr);
    for(int num : result){
        cout<<num<<" ";
    }
    cout<<endl;
}