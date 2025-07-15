#include <iostream>
using namespace std;

void pattern9(int n) {
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<n-i;j++)   
        {
            cout<<" ";
        }
        for(int j=0;j<2*i+1;j++)
        {
            cout<<"*";
        }
        for(int j=1;j<n-i;j++)   // Corrected space after stars
        {
            cout<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++)   // Loop should stop at n-1 for the second half
    {
        for(int j=1;j<=i;j++)
        {
            cout<<" ";
        }
        for(int j=0;j<2*n-(2*i+1);j++)
        {
            cout<<"*";
        }
        for(int j=1;j<=i;j++)   // Corrected space after stars
        {
            cout<<" ";
        }
        cout<<endl;
    }
}


int main() {
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    pattern9(n);
    return 0;
}
