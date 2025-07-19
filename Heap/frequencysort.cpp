// sort element which are having highest freqency and so on 

#include<bits/stdc++.h>
#define ppi pair<int, int>
using namespace std;

vector<int>frequecysort(vector<int>& nums){
    unordered_map<int, int> mpp;
    for(int num : nums){
        mpp[num]++;
    }
    priority_queue<ppi, vector<ppi>, greater<ppi>>minheap;
    for(auto it : mpp){
        minheap.push({it.second, it.first});
    }
    vector<int>result;
    while(!minheap.empty()){
        int freq = minheap.top().first;
        int element = minheap.top().second;
        minheap.pop();
        for(int i=1; i<= freq; i++){
            result.push_back(element);
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

int main(){
    vector<int>arr = {1,2,3,4,1,2,1};
    vector<int> result = frequecysort(arr);
    for(int num : result){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}