#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        int i = 0, j = 0, n1 = nums1.size(), n2 = nums2.size();
        
        while (i < n1 && j < n2) {
            if (nums1[i][0] == nums2[j][0]) { // If IDs match, sum the values
                ans.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++, j++;
            } else if (nums1[i][0] < nums2[j][0]) { // Take the smaller ID first
                ans.push_back(nums1[i++]);
            } else {
                ans.push_back(nums2[j++]);
            }
        }
        
        // Add remaining elements from nums1
        while (i < n1) ans.push_back(nums1[i++]);
        
        // Add remaining elements from nums2
        while (j < n2) ans.push_back(nums2[j++]);
        
        return ans;
    }
};

// Example usage:
int main() {
    Solution sol;
    vector<vector<int>> nums1 = {{1, 2}, {2, 3}, {4, 5}};
    vector<vector<int>> nums2 = {{1, 3}, {3, 2}, {4, 1}};
    
    vector<vector<int>> result = sol.mergeArrays(nums1, nums2);

    for (auto& v : result) {
        cout << "[" << v[0] << ", " << v[1] << "] ";
    }
    return 0;
}
