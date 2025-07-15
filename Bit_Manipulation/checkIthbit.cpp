#include<bits/stdc++.h>
using namespace std;

bool checkIthBit(int n, int i){
    return (n & (1<<i)) != 0; // depends on i bit if i bit is '0' then its false otherwise true
    // likh kr dekh
}
int main(){
    int n,i;
    cin>>n>>i;
    cout<<checkIthBit(n, i)<<endl;
    return 0;
}