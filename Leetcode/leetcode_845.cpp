#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int longestMountain(vector<int>& arr) {
            int n = arr.size();
            if (n < 3) return 0; // A mountain must have at least 3 elements
    
            int maxLength = 0;
    
            for (int i = 1; i < n - 1; i++) {
                // Check if arr[i] is a peak
                if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                    int left = i, right = i;
    
                    // Expand left side using for loop
                    for (int j = i - 1; j >= 0 && arr[j] < arr[j + 1]; j--) {
                        left = j;
                    }
    
                    // Expand right side using for loop
                    for (int j = i + 1; j < n && arr[j] < arr[j - 1]; j++) {
                        right = j;
                    }
    
                    // Calculate mountain length
                    maxLength = max(maxLength, right - left + 1);
                }
            }
    
            return maxLength;
        }
    };
    int main() {
        Solution sol;
        
        vector<int> arr = {2, 1, 4, 7, 3, 2, 5}; // Example input
        int result = sol.longestMountain(arr);
    
        cout << "Longest mountain length: " << result << endl;
    
        return 0;
    }