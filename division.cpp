#include<bits/stdc++.h>
using namespace std;

// void printDivision(int n){
//     for(int i=1; i<=n; i++){
//         if(n%i==0){
//             cout<<i<<endl;
//         }
//     }
//     cout<<endl;
// }

void printDivision(int n){
    vector<int> v;
    for(int i=1; i<=sqrt(n); i++){   // i*i<=n which is equal to i<=sqrt(n)
        if(n%i==0){
            cout<<i<<endl;
            if(n/i!=i){
                v.push_back(n/i);
            }
        }
    }
    sort(v.begin(), v.end());
    for(auto it : v) cout<<it<<endl;
}
int main(){
    int t; 
    cin>>t;
    for(int i=0; i<t; i++){
        int n;
        cin>>n;
        printDivision(n);
    }
}