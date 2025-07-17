#include<iostream>
using namespace std;
bool isPrime(int n) {
    if (n <= 1) return false; // Handle edge cases
    for (int i = 2; i * i <= n; i++) { // Check divisors up to sqrt(n)
        if (n % i == 0) return false; // If divisible, not prime
    }
    return true; // Otherwise, it's prime
}

int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        int n;
        cin>>n;
        if(isPrime(n)){
            cout<<"Prime"<<endl;
        }else{
            cout<<"Not prime"<<endl;
        }
    }
}