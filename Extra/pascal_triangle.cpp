#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);  // Fix: Initialize all elements to 1
            for (int j = 1; j < i; j++) {
                row[j] = ans[i - 1][j - 1] + ans[i - 1][j];  // Fix: Correct formula
            }
            ans.push_back(row);
        }
        return ans;
    }
};

int main() {
    int numRows = 5;
    Solution sol;
    vector<vector<int>> result = sol.generate(numRows);

    cout << "Pascal's Triangle:\n";
    for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
