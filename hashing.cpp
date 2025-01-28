#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    // precompute
    int hash[20]= {0};
    for(int i=0;i<n;i++){
        hash[v[i]]++;
    }

    // query
    int q;
    cin>>q;
    while(q--){
        int number;
        cin >> number;
        cout<<hash[number]<<endl;
    }
    return 0;
}