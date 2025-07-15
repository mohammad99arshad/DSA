#include<bits/stdc++.h>
using namespace std;

int toggleIthbit(int n, int i){
    return (n ^ (1<<i));
}

int main(){
    int n, i;
    cin>>n>>i;
    cout<<toggleIthbit(n, i)<<endl;
}