#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if ((long long)m * k > n) return -1; // Prevent integer overflow

        int low = *min_element(bloomDay.begin(), bloomDay.end()); 
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2; // Prevent overflow
            if (canMakeBouquets(bloomDay, mid, m, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }

private:
    bool canMakeBouquets(vector<int>& bloomDay, int days, int m, int k) {
        int bouquets = 0, flowers = 0;
        for (int bloom : bloomDay) {
            if (bloom <= days) {
                flowers++;
                if (flowers == k) { // One bouquet is formed
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0; // Reset if flower hasn't bloomed
            }
            if (bouquets >= m) return true;
        }
        return false;
    }
};
 

int main() {
    Solution sol;
    
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3, k = 1;
    
    cout << "Minimum days to make " << m << " bouquets: " << sol.minDays(bloomDay, m, k) << endl;

    return 0;
}