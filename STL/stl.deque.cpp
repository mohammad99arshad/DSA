#include <iostream>
#include <deque>
using namespace std;

void explainDeque() {
    deque<int> dq;
    dq.push_back(1);       // Add to the end
    dq.push_front(2);      // Add to the front
    dq.emplace_back(3);    // Efficient add at the end
    dq.emplace_front(4);   // Efficient add at the front

    dq.pop_back();         // Remove from the end
    dq.pop_front();        // Remove from the front

    cout << dq.front() << " " << dq.back() << endl; // Access front and back elements
    cout << dq[0] << " " << dq.at(0) << endl;       // Random access

    dq.insert(dq.begin() + 1, 5);   // Insert at specific position
    dq.erase(dq.begin() + 1);       // Erase at specific position
    dq.clear();                     // Clear all elements
    cout << (dq.empty() ? "Empty" : "Not Empty") << endl; // Check if empty
}

int main() {
    explainDeque();
    return 0;
}
