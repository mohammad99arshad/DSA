#include<bits/stdc++.h>
using namespace std;

// int countSetBits(int n){
//     int count = 0;
//     while(n>1){
//         count += n& 1; // n%2 =='1'
//         n = n>>1; // n = n/2
//         if(n == 1) count += 1;
//     }
//     return count;
// }

int countSetBits(int n){
    int count = 0;
    while( n!= 0){
        n = n & (n-1);
        count++;
    }
    return count;
}


int main(){
    int n;
    cin>>n;
    cout<<countSetBits(n)<<endl;
}