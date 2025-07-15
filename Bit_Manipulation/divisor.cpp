#include<bits/stdc++.h>
using namespace std;

vector<int>divisor(int n){
    vector<int>res;
    for(int i=1; i<=n; i++){
        if( n % i == 0){
            res.push_back(i);
        }
    }
    return res;
}

int main(){
    int n; 
    cin>>n; 
    vector<int> result = divisor(n);
    for(int num: result){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}