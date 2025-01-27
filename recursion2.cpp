#include <iostream>
using namespace std;

void func(int i, int n) {
    if (i < 1) {
        return;
    }
    func(i - 1, n);  // Correct recursive call
    cout << i << endl;  // Print i after the recursive call
}

int main() {
    int n;
    cin >> n;
    func(n, n);  // Start the recursive function
    return 0;
}
