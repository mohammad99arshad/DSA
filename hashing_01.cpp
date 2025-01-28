#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();

    // Initialize frequency array for lowercase letters
    int hash[26] = {0};

    // Precompute frequencies for lowercase letters
    for (int i = 0; i < n; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') { // Ensure only lowercase letters are processed
            hash[s[i] - 'a']++;
        }
    }

    int q;
    cin >> q;

    // Handle queries
    while (q--) {
        char c;
        cin >> c;

        // Check if the input is a valid lowercase letter
        if (c >= 'a' && c <= 'z') {
            cout << hash[c - 'a'] << endl;
        } else {
            cout << "0" << endl; // Output 0 for invalid or unsupported characters
        }
    }
    return 0;
}
