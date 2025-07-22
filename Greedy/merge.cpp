// leetcode 56

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> result;
    if (intervals.empty()) return result;

    // Sort intervals based on the start time
    sort(intervals.begin(), intervals.end());

    // Initialize with the first interval
    result.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {
        // Get reference to the last interval in result
        vector<int>& last = result.back();

        // If current interval overlaps, merge it
        if (intervals[i][0] <= last[1]) {
            last[1] = max(last[1], intervals[i][1]);
        } else {
            // Otherwise, add it as a new interval
            result.push_back(intervals[i]);
        }
    }

    return result;
}

int main() {
    vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};
    vector<vector<int>> merged = merge(intervals);

    for (auto& interval : merged) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;
    return 0;
}
