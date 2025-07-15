#include<bits/stdc++.h>
using namespace std;

int xortill(int n){
    if(n % 4 == 0) return 0;
    if( n% 4 == 1) return 1;
    if( n%4 == 2) return n+1;
    return 0;
}

int xorFromL2R(int l, int r){
    return xortill(r) ^ xortill(l-1);
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<xorFromL2R(a, b)<<endl;
}