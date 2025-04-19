#include <bits/stdc++.h>
using namespace std;

class stackk
{
public:
  int topIndex = -1;
  int st[20];

  void push(int x)
  {
    if (topIndex == 19)
    {
      cout << "Stack Overflow\n";
    }
    else
    {
      topIndex++;
      st[topIndex] = x;
    }
  }
  int top()
  {
    if (topIndex == -1)
    {
      cout << "Stack is empty\n";
      return -1;
    }
    else
    {
      return st[topIndex];
    }
  }

  void pop(int x)
  {
    if (topIndex == -1)
    {
      cout << "stack is empty\n";
    }
    else
    {
      cout << st[topIndex] << " is popped\n";
      topIndex--;
    }
  }
  void size()
  {
    cout << "size of stack is " << topIndex + 1 << "\n";
  }
};

int main()
{
  stack<int> s;
  s.push(10);
  s.push(20);
  s.push(30);
  cout << "Top element is " << s.top() << "\n";
  cout << "size of stack is " << s.size() << "\n";
  s.pop();
  cout << "Top element is " << s.top() << "\n";
  return 0;
}