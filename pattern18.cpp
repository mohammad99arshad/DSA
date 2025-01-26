#include<iostream>
using namespace std;
void pattern18(int n){
    for (int i = 0; i < n; i++) {
    char start = 'A' + (n - 1); // Dynamically calculate the starting character
    for (char ch = start; ch >= start - i; ch--) { // Loop backward from the starting character
        cout << ch << " ";
    }
    cout << endl;
    }
}
int main(){
    int t;
    cout<<"Enter the number of test cases: ";
    cin>>t;
    for(int i=0; i<t; i++){
        int n;
        cout<<"Enter the number of rows: ";
        cin>>n;
        pattern18(n);
    }
    return 0;
}