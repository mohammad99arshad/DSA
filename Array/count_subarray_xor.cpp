#include <bits/stdc++.h>
using namespace std;

int subarraysWithSumK(vector<int> a, int b) {
    int count = 0;
    int xorr = 0;  

    for (int i = 0; i < a.size(); i++) {
        xorr = 0;  
        for (int j = i; j < a.size(); j++) {  
            xorr ^= a[j];  
            if (xorr == b) count++;
        }
    }
    return count;  
}

int main() {
    vector<int> a = {4, 2, 2, 6, 4}; 
    int b = 6;
    cout << subarraysWithSumK(a, b) << endl;
    return 0;
}
