#include<iostream>
using namespace std;

bool palindrome(int n)
{
    int revNum = 0;
    int nn = n;  // Store the original number to compare later

    // Reverse the number
    while(n > 0) {
        int lastDigit = n % 10;
        revNum = revNum * 10 + lastDigit;
        n = n / 10;
    }

    // Check if the reversed number is equal to the original
    if(revNum == nn) 
        return true;
    else
        return false;
}


int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        palindrome(n);  // Pass the number to reverse and check palindrome
    }
}
