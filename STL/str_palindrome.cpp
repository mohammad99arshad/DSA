// #include <iostream>
// using namespace std;

// bool palindrome(int i, string& s){
    
//     // Base Condition
//     // If i exceeds half of the string means all the elements 
//     // are compared, we return true.
//     if(i>=s.length()/2) return true;
    
//     // If the start is not equal to the end, not the palindrome.
//     if(s[i]!=s[s.length()-i-1]) return false;
    
//     // If both characters are the same, increment i and check start+1 and end-1.
//     return palindrome(i+1,s);
// }

// int main() {
//     string s;
//     cout << "Enter a string: ";
//     cin >> s; // Take string input from the user
//     if (palindrome(0, s))
//         cout << "The string is a palindrome." << endl;
//     else
//         cout << "The string is not a palindrome." << endl;
//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;

void palindrome(int i, int n, string &s) {
    if (i >= n / 2) {
        return; // Base case: stop recursion when the midpoint is reached.
    }
    swap(s[i], s[n - i - 1]); // Swap characters at i and n-i-1.
    palindrome(i + 1, n, s);  // Recursive call for the next index.
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s; // Take input string from the user.
    palindrome(0, s.length(), s); // Start recursion from index 0.
    cout << "Reversed string: " << s << endl; // Output the reversed string.
    return 0;
}
