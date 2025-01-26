#include <iostream>
#include <stack>
using namespace std;

void explainStack() {
    stack<int> s;
    s.push(1);          // Push 1 onto the stack
    s.push(2);          // Push 2 onto the stack
    s.emplace(3);       // Efficiently push 3 onto the stack

    cout << "Top element: " << s.top() << endl; // Access the top element

    s.pop();           // Remove the top element
    cout << "After pop, top element: " << s.top() << endl;

    cout << "Stack size: " << s.size() << endl; // Get the size of the stack
    cout << (s.empty() ? "Empty" : "Not Empty") << endl; // Check if stack is empty

    s.pop();
    s.pop();
    cout << "After popping all elements: " << (s.empty() ? "Empty" : "Not Empty") << endl;
}

int main() {
    explainStack();
    return 0;
}
