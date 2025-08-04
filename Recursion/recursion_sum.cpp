#include <iostream>
using namespace std;

// int func(int n) {
//     if (n == 0) {
//         return 0;  // Base case: the sum of first 1 number is 1
//     }
//     return n + func(n - 1);  // Recursive call, summing n and the sum of first (n-1) numbers
// }

// int main() {
//     int n;
//     cin >> n;
//     cout << func(n) << endl;  // Print the result of the recursive function
//     return 0;
// }

int func(int i, int sum){
    if(i < 1){
        cout << sum << endl;
        return sum;
    }
    return func(i - 1, sum + i);
}

int main(){
    int i, sum = 0;
    cin >> i;
    func(i, sum);  
    return 0;
}

