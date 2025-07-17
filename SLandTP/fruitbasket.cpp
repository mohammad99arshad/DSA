#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int>& fruits) {
    unordered_map<int, int> basket;
    int left = 0, maxlen = 0;

    for (int right = 0; right < fruits.size(); right++) {
        basket[fruits[right]]++;

        while (basket.size() > 2) {
            basket[fruits[left]]--;
            if (basket[fruits[left]] == 0) {
                basket.erase(fruits[left]);
            }
            left++;
        }

        maxlen = max(maxlen, right - left + 1);
    }

    return maxlen;
}

int main() {
    vector<int> fruits = {1, 2, 1};
    cout << totalFruit(fruits) << endl;
    return 0;
}
