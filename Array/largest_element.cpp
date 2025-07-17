#include <bits/stdc++.h>
using namespace std;

int largestElement(vector<int>& arr, int size) {
    int largestElement = arr[0];  // Initialize with the first element

    for (int i = 1; i < size; i++) {  // Loop through the array
        if (arr[i] > largestElement) {
            largestElement = arr[i];  // Update the largest value
        }
    }

    return largestElement;  // Return the maximum element
}

int main() {
    int n;
    cin >> n;  // Read array size

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // Read array elements
    }

    cout << largestElement(arr, n) << endl;  // Print the largest element

    return 0;
}
