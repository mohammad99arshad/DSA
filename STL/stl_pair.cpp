#include<iostream>
using namespace std;

void explainPair(){
    // Correctly initializing a pair
    pair<int, int> p = {1, 3};
    cout << p.first << " " << p.second << endl;

    // Correctly initializing a nested pair
    pair<int, pair<int, int>> p1 = {1, {3, 4}};
    cout << p1.first << " " << p1.second.first << " " << p1.second.second << endl;

    // Correctly initializing an array of pairs
    pair<int, int> arr[] = {{1, 2}, {2, 3}, {3, 4}};
    cout << arr[0].first << " " << arr[0].second << endl;
}

int main() {
    explainPair();
    return 0;
}
