// number of substring containing all three characters

#include<bits/stdc++.h>
using namespace std;

int numberOfsubstrings(string s) {
    int lastseen[3];
    fill(begin(lastseen), end(lastseen), -1);  // Set all to -1
    int count = 0;

    for (int i = 0; i < s.size(); i++) {
        lastseen[s[i] - 'a'] = i;
        if (lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1) {
            count += (1 + min({lastseen[0], lastseen[1], lastseen[2]}));
        }
    }
    return count;
}

int main() {
    string s = "abcabc";
    cout << numberOfsubstrings(s)<<endl;
    return 0;
}
