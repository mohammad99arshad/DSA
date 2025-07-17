#include <bits/stdc++.h>
using namespace std;

vector<int> sortedArray(vector<int> a, vector<int> b) {
    int n1 = a.size(), n2 = b.size();
    vector<int> result;
    int i = 0, j = 0;

    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            if (result.empty() || result.back() != a[i])
                result.push_back(a[i]);
            i++;
        } else if (a[i] > b[j]) {
            if (result.empty() || result.back() != b[j])
                result.push_back(b[j]);
            j++;
        } else {
            if (result.empty() || result.back() != a[i])
                result.push_back(a[i]);
            i++;
            j++;
        }
    }
    
    while (i < n1) {
        if (result.empty() || result.back() != a[i])
            result.push_back(a[i]);
        i++;
    }

    while (j < n2) {
        if (result.empty() || result.back() != b[j])
            result.push_back(b[j]);
        j++;
    }

    return result;
}

// Sample Usage
int main() {
    vector<int> a = {1, 2, 3, 4, 6};
    vector<int> b = {2, 3, 5, 7};
    vector<int> result = sortedArray(a, b);

    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
