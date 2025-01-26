#include <iostream>
#include <list>
using namespace std;

void explainList() {
    list<int> l;
    l.push_back(1);       // Add to the end
    l.push_front(2);      // Add to the front
    l.emplace_back(3);    // Efficient add at the end
    l.emplace_front(4);   // Efficient add at the front

    l.pop_back();         // Remove last element
    l.pop_front();        // Remove first element

    auto it = l.begin();
    l.insert(it, 5);      // Insert 5 at the beginning
    l.insert(it, 2, 6);   // Insert two 6s at the beginning
    l.erase(it);          // Erase the first element

    l.sort();             // Sort the list
    l.reverse();          // Reverse the list
    l.remove(6);          // Remove all 6s

    list<int> l2 = {10, 20, 30};
    l.merge(l2);          // Merge sorted l2 into l

    l.clear();            // Clear the list
    cout << (l.empty() ? "Empty" : "Not Empty") << endl;
}

int main() {
    explainList();
    return 0;
}
