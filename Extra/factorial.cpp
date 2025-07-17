#include <iostream>
using namespace std;

// void func(int i, int fact) {
//     if (i > 1) {  // Base case: factorial is computed when i reaches 1
//         func(i - 1, fact * i);  // Recursively call with i - 1 and multiply fact by i
//     } else {
//         cout << fact << endl;  // Print the final factorial value when i reaches 1
//     }
// }

void func(int i, int fact){
    if(i == 0){
        cout << fact << endl;
    } else {
        func(i - 1, fact * i);
    }
}

int main() {
    int n;
    cin >> n;  // Input the number for factorial
    func(n, 1);  // Call the recursive function with n and initial fact = 1
    return 0;
}
