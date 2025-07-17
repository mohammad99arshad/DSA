#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int left = 0, right = 0;
    int maxlen = 0;
    int n = s.size();
    vector<int> mapp(256, -1);  // For all ASCII characters

    while (right < n) {
        if (mapp[s[right]] != -1 && mapp[s[right]] >= left) {
            left = mapp[s[right]] + 1;
        }

        int len = right - left + 1;
        maxlen = max(maxlen, len);
        mapp[s[right]] = right;

        right++;
    }

    return maxlen;
}

int main() {
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}
