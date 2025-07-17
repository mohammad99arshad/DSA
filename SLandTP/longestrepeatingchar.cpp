
#include <bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k) {
    int l = 0, maxfreq = 0, result = 0;
    int hash[26] = {0};

    for (int i = 0; i < s.size(); i++) {
        hash[s[i] - 'A']++;  // Increment frequency of current char
        maxfreq = max(maxfreq, hash[s[i] - 'A']);  // Track max frequency char

        // If more than k replacements are needed, shrink window
        if ((i - l + 1) - maxfreq > k) {
            hash[s[l] - 'A']--;
            l++;
        }

        result = max(result, i - l + 1);  // Update max window size
    }

    return result;
}

int main() {
    string s = "AABABBA";
    int k = 1;
    cout << characterReplacement(s, k) << endl;
    return 0;
}
