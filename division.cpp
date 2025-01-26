#include<iostream>
using namespace std;

void printDivision(int n){
    for(int i=1; i<=n; i++){
        if(n%i==0){
            cout<<i<<endl;
        }
    }
    cout<<endl;
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