#include<iostream>
#include<cmath>  // For abs()
using namespace std;

int countDigits(int n){
    // Use the absolute value of n to handle negative numbers
    int cnt = 0;
    n = abs(n);  // Take absolute value of n
    while(n > 0){
        int lastDigit = n % 10;
        cnt = cnt + 1;
        n = n / 10;
    }
    return cnt;
}

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        cout << countDigits(n) << endl;
    }
}