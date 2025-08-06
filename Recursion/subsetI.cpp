#include<bits/stdc++.h>
using namespace std;

void tsubset(int ind, vector<int>& arr, int n, vector<int>& ans, int sum){
    if(ind == n){
        ans.push_back(sum);
        return;
    }
    tsubset(ind+1, arr, n, ans, sum+arr[ind]);
    tsubset(ind+1, arr, n, ans, sum);
}

vector <int> subsetSums(vector < int > arr, int n){
    vector<int>result;
    tsubset(0, arr, n, result, 0);
    sort(result.begin(), result.end());
    return result;
}

int main(){
    vector<int>arr{3,2,1};
    vector<int>res = subsetSums(arr, arr.size());
    for(auto sum : res){
        cout<<sum<<" ";
    }
    cout<<endl;
    return 0;
}