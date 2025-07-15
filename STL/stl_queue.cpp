#include <iostream>
#include <queue>
using namespace std;

void explainQueue() {
    queue<int> q;
    q.push(1);          // Push 1 to the back
    q.push(2);          // Push 2 to the back
    q.emplace(3);       // Efficiently push 3 to the back

    cout << "Front element: " << q.front() << endl; // Access the front element
    cout << "Back element: " << q.back() << endl;   // Access the back element

    q.pop();           // Remove the front element
    cout << "After pop, front element: " << q.front() << endl;

    cout << "Queue size: " << q.size() << endl;    // Get the size of the queue
    cout << (q.empty() ? "Empty" : "Not Empty") << endl; // Check if queue is empty
}

int main() {
    explainQueue();
    return 0;
}
