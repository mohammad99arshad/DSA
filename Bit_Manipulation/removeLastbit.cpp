#include<bits/stdc++.h>
using namespace std;

int removeIthbit(int n){
    return (n & (n-1));
}

int main(){
    int n;
    cin>>n;
    cout<<removeIthbit(n)<<endl;
}