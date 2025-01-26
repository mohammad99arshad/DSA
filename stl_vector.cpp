#include <iostream>
#include <vector>
using namespace std;

void explainVector() { // STL means Standard Template Library
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);

    vector<pair<int, int>> vp;
    vp.push_back({1, 2}); // Fixed: Adding to the vector of pairs
    vp.emplace_back(2, 3);

    vector<int> v2(4, 50); // Vector of size 4 with all elements initialized to 50

    vector<int> v3(4); // Vector of size 4 with all elements initialized to 0

    vector<int> v4 = {1, 2, 3, 4, 5}; // Vector initialized with a list of values
    vector<int> v5(v4); // Copy of vector v4

    vector<int>::iterator it = v.begin();
    it++;
    cout << *(it) << endl;

    it = it + 1; // Move the iterator 1 position ahead
    cout << *(it) << endl;

    // Correct iterator declarations
    vector<int>::iterator it1 = v.end(); // Points to one past the last element
    vector<int>::reverse_iterator it2 = v.rend(); // Corrected to reverse_iterator
    vector<int>::reverse_iterator it3 = v.rbegin(); // Corrected to reverse_iterator

    cout << v[0] << " " << v.at(0) << endl;
    cout <<  v.back() << endl;

    // Using iterators to iterate through the vector
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // Using auto keyword for cleaner code
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // Using range-based for loop
    for (auto it : v) {
        cout << it << " ";
    }
    cout << endl;

    // Erase operations
    v.erase(v.begin() + 1); // Erase the second element
    v.erase(v.begin() + 2, v.begin() + 4); // Erase a range of elements

    // Insert operations
    v.insert(v.begin(), 10); // Insert 10 at the beginning
    v.insert(v.begin() + 1, 2, 20); // Insert two 20s at position 1

    vector<int> copy(2, 50); // Vector with two elements initialized to 50
    v.insert(v.begin(), copy.begin(), copy.end()); // Insert all elements of 'copy' at the beginning of 'v'

    cout << v.size() << endl; // Print size of the vector

    // Pop back operation
    v.pop_back();

    // Swap operation
    v.swap(v2); // Swap contents of v and v2

    // Clear the vector
    v.clear();

    // Check if the vector is empty
    cout << v.empty() << endl;
}

int main() {
    explainVector();
    return 0;
}
