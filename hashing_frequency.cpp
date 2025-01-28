#include <bits/stdc++.h>
using namespace std;

void func(int arr[], int n) {
    unordered_map<int, int> ump;

    // Count the frequency of each element
    for (int i = 0; i < n; i++) {
        ump[arr[i]]++;
    }

    int max_freq = 0, min_freq = INT_MAX;
    int max_freq_ele = 0, min_freq_ele = 0;

    // Find the elements with maximum and minimum frequency
    for (auto it : ump) {
        int count = it.second;
        int ele = it.first;

        if (count > max_freq) {
            max_freq = count;
            max_freq_ele = ele;
        }

        if (count < min_freq) {
            min_freq = count;
            min_freq_ele = ele;
        }
    }

    cout << "Element with max frequency: " << max_freq_ele << " (Frequency: " << max_freq << ")" << endl;
    cout << "Element with min frequency: " << min_freq_ele << " (Frequency: " << min_freq << ")" << endl;
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    func(arr, n);
    return 0;
}
