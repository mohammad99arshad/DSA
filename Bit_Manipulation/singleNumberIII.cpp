#include<bits/stdc++.h>
using namespace std;

vector<int> singleNumber(vector<int>& nums) {
    int xorsum = 0;
    for (int num : nums)
        xorsum ^= num;

    int diffBit = xorsum & -xorsum;

    int num1 = 0, num2 = 0;
    for (int num : nums) {
        if (num & diffBit)
            num1 ^= num;
        else
            num2 ^= num;
    }

    return {num1, num2};
}

int main() {
    vector<int> arr = {1, 2, 1, 3, 5, 2};
    vector<int> result = singleNumber(arr);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}