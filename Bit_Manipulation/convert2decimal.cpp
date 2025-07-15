#include <bits/stdc++.h>
using namespace std;

int convert2Decimal(string s) {
    int n = s.length();
    int num = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '1') { //'0' ki jarurat nhi h kyuki multiply karne ke bad to '0' hi ana hai 
            num += pow(2, n - i - 1);   // shift bhi use kar sakte the 
            //num += 1 << (n - i - 1);
        }
    }
    return num;
}

int main() {
    string s;
    cin >> s;
    cout << convert2Decimal(s) << endl;
    return 0;
}
// space complexity: O(len)
//time : O(log)