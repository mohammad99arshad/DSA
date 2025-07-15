#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0; // Edge case

        int minPrice = INT_MAX;  // To track the lowest buying price
        int maxProfit = 0;       // To track the highest profit

        for (int i = 0; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);           // Update minPrice
            maxProfit = max(maxProfit, prices[i] - minPrice); // Update maxProfit
        }

        return maxProfit;
    }
};

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution sol;
    cout << "Max Profit: " << sol.maxProfit(prices) << endl;
    return 0;
}
