#include <iostream>
#include <stack>
using namespace std;

// Insert an element at the bottom of the stack
void insertAtBottom(stack<int> &st, int x)
{
  if (st.empty())
  {
    st.push(x);
    return;
  }
  int top = st.top();
  st.pop();
  insertAtBottom(st, x);
  st.push(top);
}

// Reverse the stack using recursion
void reverseStack(stack<int> &st)
{
  if (st.empty())
    return;
  int top = st.top();
  st.pop();
  reverseStack(st);
  insertAtBottom(st, top);
}

// Print stack contents (without modifying original)
void printStack(stack<int> st)
{
  while (!st.empty())
  {
    cout << st.top() << " ";
    st.pop();
  }
  cout << endl;
}

int main()
{
  stack<int> st;

  // Push elements: bottom will be 1, top will be 4
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);

  cout << "Original stack (top to bottom): ";
  printStack(st); // Will print 4 3 2 1

  // Reverse the stack
  reverseStack(st);

  cout << "Reversed stack (top to bottom): ";
  printStack(st); // Will print 1 2 3 4
  return 0;
}
