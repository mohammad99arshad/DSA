#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a) {
    vector<int> ans;
    sort(a.begin(), a.end());
    int n = a.size();
    
    int repeating = -1, missing = -1;
    
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) repeating = a[i];
    }

    for (int i = 1; i <= n; i++) {
        if (!binary_search(a.begin(), a.end(), i)) {
            missing = i;
            break;
        }
    }

    ans.push_back(repeating);
    ans.push_back(missing);
    
    return ans;
}

int main() {
    vector<int> a = {1, 2, 3, 2};
    vector<int> result = findMissingRepeatingNumbers(a);

    cout << "Repeating: " << result[0] << "\n";
    cout << "Missing: " << result[1] << "\n";

    return 0;
}
