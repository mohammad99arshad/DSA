#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2; // Prevent overflow
            if (countDays(weights, mid) <= days) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

private:
    int countDays(vector<int>& weights, int capacity) {
        int days = 1, currentLoad = 0;
        for (int weight : weights) {
            if (currentLoad + weight > capacity) {
                days++; // Need an extra day
                currentLoad = 0;
            }
            currentLoad += weight;
        }
        return days;
    }
};
int main() {
    Solution sol;
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;

    cout << "Minimum ship capacity: " << sol.shipWithinDays(weights, days) << endl;
    return 0;
}
