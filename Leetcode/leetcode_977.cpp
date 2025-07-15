#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> squares;
        
        // Compute squares of each number
        for (int num : nums) {
            squares.push_back(num * num);
        }

        // Sort the squared values
        sort(squares.begin(), squares.end());

        return squares;
    }
};

int main() {
    vector<int> nums = {-4, -1, 0, 3, 10};
    Solution sol;
    vector<int> result = sol.sortedSquares(nums);

    // Print result
    cout << "Sorted Squares: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
