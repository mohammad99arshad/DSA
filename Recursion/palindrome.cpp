#include <bits/stdc++.h>
using namespace std;

bool palindrome(string& s, int i, int n){
    if(i >= n / 2) return true;
    if(s[i] != s[n - i - 1]) return false;
    return palindrome(s, i + 1, n);
}

int main(){
    string s;
    cin >> s;
    int n = s.size();

    if (palindrome(s, 0, n)) {
        cout << "Yes, it is a palindrome." << endl;
    } else {
        cout << "No, it is not a palindrome." << endl;
    }

    return 0;
}
