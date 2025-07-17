#include <bits/stdc++.h>
using namespace std;

void arrayShift(int arr[], int n, int k) {    
    for (int i = 0; i < k; i++) {
        int temp = arr[0];
        
        // Shift all elements one position to the left
        for (int j = 0; j < n - 1; j++) {
            arr[j] = arr[j + 1];
        }
        
        // Move the first element to the last position
        arr[n - 1] = temp;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    
    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;    
    arrayShift(arr, n, k);    
    cout << "Array after " << k << " shifts: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
