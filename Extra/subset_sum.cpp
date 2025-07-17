#include<bits/stdc++.h>

using namespace std;

void findSubsets(vector<int>& nums, vector<int>& subset, int index, int sum, int count) {
    if (count == 5) {
        if (sum == 0) {
            for (int num : subset) cout << num << " ";
            cout << endl;
        }
        return;
    }
    
    for (int i = index; i < nums.size(); i++) {
        subset.push_back(nums[i]);
        findSubsets(nums, subset, i + 1, sum + nums[i], count + 1);
        subset.pop_back();
    }
}

int main() {
    vector<int> A = {-12, -3, -6, 7, 2, -2, 6, 3, 9, -7, -5, -8, 1, 11, -9, -4, 5, -11, 12, -8};
    vector<int> subset;
    findSubsets(A, subset, 0, 0, 0);
    return 0;
}
