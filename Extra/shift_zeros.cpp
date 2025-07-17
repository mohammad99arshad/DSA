#include <bits/stdc++.h>
using namespace std;

vector<int> moveZeros(int n, vector<int>& a) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            swap(a[i], a[j]);
            j++;
        }
    }
    return a;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    a = moveZeros(n, a);
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
