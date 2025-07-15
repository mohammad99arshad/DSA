#include <iostream>
using namespace std;

void func(int i, int n);  // Function prototype

int main() {
    int n;
    cin >> n;
    func(1, n);  // Calling func
    return 0;
}

void func(int i, int n) {  // Function definition
    if (i > n) {
        return;  // Base case: stop recursion when i exceeds n
    }
    cout << "Arshad" << endl;  // Correct way to print new line
    func(i + 1, n);  // Recursive call with i incremented
}
