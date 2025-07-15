#include<iostream>
using namespace std;

void pattern19(int n) {
    int isIs = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n - i; j++) { // Fixed condition to include last star
            cout << "*";
        }
        for (int j = 0; j < isIs; j++) { // Space logic is fine
            cout << " ";
        }
        for (int j = 1; j <= n - i; j++) { // Fixed condition to include last star
            cout << "*";
        }
        isIs += 2; // Space increment logic is fine
        cout << endl;
    }
    
    int isIS = 2 * (n - 1); // Initialize based on the number of spaces needed
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) { // Left stars
            cout << "*";
        }
        for (int j = 0; j < isIS; j++) { // Spaces in the middle
            cout << " ";
        }
        for (int j = 1; j <= i; j++) { // Right stars
            cout << "*";
        }
        isIS -= 2; // Decrease space count
        cout << endl;
    }
}

int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;
    while (t--) {
        int n;
        cout << "Enter the number of rows: ";
        cin >> n;
        pattern19(n);
    }
}
