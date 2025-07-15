#include <iostream>
#include <set>
using namespace std;

void explainSet() {
    set<int> s;

    // Insert elements into the set. Duplicates are ignored automatically.
    s.insert(1);
    s.insert(2);
    s.insert(2);  // This will not insert the second 2
    s.insert(3);
    s.emplace(5);  // Efficient insertion of 5
    s.emplace(4);  // Efficient insertion of 4

    // Find an element
    auto it = s.find(2);  // It will point to the element 2 if found, or s.end() if not.
    if (it != s.end()) {
        cout << "Found: " << *it << endl; // Output: Found: 2
    }

    auto it2 = s.find(7);  // Not found, returns s.end()
    if (it2 == s.end()) {
        cout << "7 not found" << endl;
    }

    // Erase an element by value
    s.erase(5);  // Removes 5 from the set

    // Count occurrences of an element
    int cnt = s.count(2);  // Returns 1 since 2 is present in the set
    cout << "Count of 2: " << cnt << endl;  // Output: Count of 2: 1

    // Erase element by iterator
    auto it3 = s.find(3);
    s.erase(it3);  // Removes the element at the iterator position (3 in this case)

    // Erase elements by range of iterators
    auto it4 = s.find(4);
    auto it5 = s.find(3);  // it5 is past the element 3, meaning 3 will be excluded from the range
    s.erase(it4, it5);  // This will erase 4 (from it4 to it5, excluding it5)

    // lower_bound and upper_bound
    auto lb = s.lower_bound(2);  // Finds the first element not less than 2
    if (lb != s.end()) {
        cout << "Lower bound of 2: " << *lb << endl;
    }

    auto ub = s.upper_bound(2);  // Finds the first element greater than 2
    if (ub != s.end()) {
        cout << "Upper bound of 2: " << *ub << endl;
    }
}

int main() {
    explainSet();
    return 0;
}
