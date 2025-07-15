#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> om;

        for (char ch : s) {
            om[ch]++;
        }

        vector<pair<int, char>> freq;
        for (auto it : om) {
            freq.push_back({it.second, it.first});
        }

        sort(freq.rbegin(), freq.rend());

        string result = "";
        for (auto it : freq) {
            result += string(it.first, it.second);
        }

        return result;
    }
};

int main() {
    Solution sol;
    string s = "tree";
    cout << sol.frequencySort(s) << endl;
    return 0;
}
