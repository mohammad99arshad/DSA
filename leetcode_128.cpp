#include <bits/stdc++.h>
using namespace std;

int longestSuccessiveElements(vector<int>& a) {
    unordered_set<int> st(a.begin(), a.end()); // Store all elements in a set
    int maxlen = 0;

    for (int num : st) {
        // Check if num is the start of a sequence
        if (st.find(num - 1) == st.end()) {
            int temp = 1, current = num;

            // Expand the sequence
            while (st.find(current + 1) != st.end()) {
                current++;
                temp++;
            }

            maxlen = max(maxlen, temp);
        }
    }

    return maxlen;
}

// Example usage
int main() {
    vector<int> a = {100, 4, 200, 1, 3, 2};
    cout << longestSuccessiveElements(a); // Output: 4 (sequence: 1, 2, 3, 4)
    return 0;
}
