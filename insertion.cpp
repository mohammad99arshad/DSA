#include <bits/stdc++.h>
using namespace std;

void func(int arr[], int n) { // Change return type to void since it doesn't return anything
    for (int i = 1; i < n; i++) { // Start from i = 1 (Insertion Sort logic)
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) { // Fix misplaced parenthesis in condition
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    func(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
