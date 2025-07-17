#include<iostream>
using namespace std;

int reverse(int n){
    int revNum=0;
    while(n>0){
        int lastDigit = n % 10;
        revNum = revNum * 10 + lastDigit;
        n = n / 10;
    }
    cout<<revNum<<endl;
}
int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        reverse(n);
    }
}