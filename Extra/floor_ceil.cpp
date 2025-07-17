#include<bits/stdc++.h>
using namespace std;

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
    int low = 0, high = n - 1;
    int floor_val = -1, ceil_val = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] == x) {
            return {x, x}; // Exact match
        }
        if (a[mid] < x) {
            floor_val = a[mid]; // Possible floor
            low = mid + 1;
        } else {
            ceil_val = a[mid]; // Possible ceil
            high = mid - 1;
        }
    }
    return {floor_val, ceil_val}; // Return correct floor and ceil values
}

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    pair<int, int> result = getFloorAndCeil(a, n, x);
    cout << "Floor: " << result.first << ", Ceil: " << result.second << endl;

    return 0;
}
