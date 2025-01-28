#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();

    // Initialize frequency array for all ASCII characters
    int hash[256] = {0};

    // Precompute frequencies for all characters in the string
    for (int i = 0; i < n; i++) {
        hash[s[i]]++;
    }

    int q;
    cin >> q;

    // Handle queries
    while (q--) {
        char c;
        cin >> c;
        cout << hash[c] << endl;
    }

    return 0;
}
