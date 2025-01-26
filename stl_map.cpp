#include <iostream>
#include <map>
using namespace std;

void explainMap() {
    map<int, string> m;

    // Insert elements using insert() and emplace()
    m.insert({1, "One"});
    m.insert({2, "Two"});
    m.insert({3, "Three"});
    m.emplace(4, "Four");

    // Access elements using the key
    cout << "Value at key 2: " << m[2] << endl; // Using operator[]
    cout << "Value at key 3: " << m.at(3) << endl; // Using at()

    // Find a key
    auto it = m.find(3);
    if (it != m.end()) {
        cout << "Found key 3: " << it->second << endl; // Access the value through iterator
    }

    // Erase a key-value pair
    m.erase(2); // Erase the element with key 2

    // Count the occurrences of a key
    cout << "Count of key 2: " << m.count(2) << endl; // Should be 0 after erasure

    // Display the entire map
    cout << "All elements in the map:" << endl;
    for (auto& pair : m) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // Lower bound and upper bound
    auto lb = m.lower_bound(3);  // Finds the first element not less than 3
    if (lb != m.end()) {
        cout << "Lower bound for key 3: " << lb->first << " -> " << lb->second << endl;
    }

    auto ub = m.upper_bound(3);  // Finds the first element greater than 3
    if (ub != m.end()) {
        cout << "Upper bound for key 3: " << ub->first << " -> " << ub->second << endl;
    }
}

int main() {
    explainMap();
    return 0;
}
