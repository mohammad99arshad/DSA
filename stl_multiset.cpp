#include <iostream>
#include <set>
using namespace std;

void explainMultiSet() {
    multiset<int> ms;

    // Insert elements. Duplicates are allowed in multiset.
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);

    // Erase all occurrences of 1
    ms.erase(1);

    // Count occurrences of 1 (should be 0 after the erase operation)
    int cnt = ms.count(1);  // Returns 0 since 1 is no longer in the multiset
    cout << "Count of 1: " << cnt << endl;  // Output: Count of 1: 0

    // Re-insert 1 for demonstration purposes
    ms.insert(1);
    ms.insert(1);

    // Erase one occurrence of 1 (using find iterator)
    ms.erase(ms.find(1));

    // Reinsert 1 for range erasure demonstration
    ms.insert(1);

    // Erase a range of occurrences of 1
    auto it1 = ms.find(1);
    auto it2 = ms.find(1);  // Find the next occurrence of 1
    ++it2;  // Increment to point to the second occurrence
    ms.erase(it1, it2);  // Erase two occurrences of 1

    // Display the multiset content
    cout << "Remaining elements in multiset: ";
    for (auto x : ms) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    explainMultiSet();
    return 0;
}
