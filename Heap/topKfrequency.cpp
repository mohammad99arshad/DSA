// top k frequency numbers

#include<bits/stdc++.h>
#define ppi pair<int, int>
using namespace std;

vector<int>topkthfrequecy(vector<int>& nums, int k){
    unordered_map<int, int> mpp;
    priority_queue<ppi, vector<ppi>, greater<ppi>>minheap;

    for (int num : nums) {
        mpp[num]++;
    }

    for (auto it : mpp) {
        minheap.push({it.second, it.first});
        if (minheap.size() > k) {
            minheap.pop();
        }
    }
    vector<int>result;
    while(!minheap.empty()){
        result.push_back(minheap.top().second);
        minheap.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

int main(){
    vector<int>arr= {1,2,3,1,2,1,4};
    int n= 2;
    vector<int> res = topkthfrequecy(arr, n);
    for(int num : res){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}