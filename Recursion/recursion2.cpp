#include <iostream>
using namespace std;

void func(int i, int n) {
    if (i > n) {
        return;
    }
    cout << i << endl;  // Print i after the recursive call
    func(i + 1, n);  // Correct recursive call
}

int main() {
    int i;
    cin >> i;
    func(1, i);  // Start the recursive function
    return 0;
}


// void function (int i, int n){
//     if(i < 1){
//         return ;
//     }
//     func(i-1, n);
//     cout<<i<<endl;
// }
// int main(){
//     int  i;
//     cin>>i;
//     func(i, i);
//     return 0;
// }
