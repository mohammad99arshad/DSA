#include <iostream>
#include <map>
using namespace std;

void explainMultiMap() {
    multimap<int, string> mm;

    // Insert elements with duplicate keys
    mm.insert({1, "One"});
    mm.insert({1, "Uno"});
    mm.insert({2, "Two"});
    mm.insert({3, "Three"});
    mm.insert({3, "Trois"});
    mm.emplace(4, "Four");

    // Access elements by key
    cout << "Values at key 1: ";
    auto range = mm.equal_range(1);  // Get a range of elements with key 1
    for (auto it = range.first; it != range.second; ++it) {
        cout << it->second << " ";  // Access value via iterator
    }
    cout << endl;

    // Count occurrences of a key
    cout << "Count of key 3: " << mm.count(3) << endl;  // Output: 2 (since 3 appears twice)

    // Erase a single element by key (removes one occurrence of key 3)
    mm.erase(3);  // Erases one element with key 3

    // Erase all elements by key (removes all occurrences of key 1)
    mm.erase(1);

    // Display the multimap content
    cout << "Remaining elements in the multimap:" << endl;
    for (auto& pair : mm) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // Find an element and display it
    auto it = mm.find(2);
    if (it != mm.end()) {
        cout << "Found key 2: " << it->second << endl;
    }
}

int main() {
    explainMultiMap();
    return 0;
}
