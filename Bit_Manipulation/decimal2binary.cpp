#include<bits/stdc++.h>
using namespace std;

string converttoBinary(int n) {
    string res = "";
    if (n == 0) return "0";  // edge case 
    while (n > 0) {
        if (n % 2 == 1) {
            res += '1';  // '1' ko joda jaega
        } else {
            res += '0';  // nhi to '0' ko
        }
        n = n / 2;
    }
    reverse(res.begin(), res.end());  // string ko reverse kia jaega after loop kyuki answer ulta mil rha h
    return res;
}

int main() {
    int n = 45;  
    cout << converttoBinary(n) << endl;  
    return 0;
}


// space and time complextiy are : O(log n)
