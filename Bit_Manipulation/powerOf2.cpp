#include<bits/stdc++.h>
using namespace std;

int powerOftwo(int n){
    return (n & (n-1) == '0');
}

int main(){
    int n;
    cin>>n;
    cout<<powerOftwo(n)<<endl;
}