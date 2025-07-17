#include<iostream>
using namespace std;

int main(){
    int n, sum = 0, temp, rem;
    cout<<"Enter a number: ";
    cin>>n;
    temp = n;
    while(n > 0){
        rem = n % 10;
        sum += rem * rem * rem;
        n /= 10;
    }
    if(temp == sum){
        cout<<temp<<" is an Armstrong number."<<endl;
    } else {
        cout<<temp<<" is not an Armstrong number."<<endl;
    }
}