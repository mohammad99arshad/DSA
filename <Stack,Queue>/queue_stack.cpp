#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
  stack<int> s1, s2;

public:
  void push(int x)
  {
    while (s1.size())
    {
      s2.push(s1.top());
      s1.pop();
    }
    s1.push(x);
    while (s2.size())
    {
      s1.push(s2.top());
      s2.pop();
    }
  }

  void pop()
  {
    if (!s1.empty())
    {
      s1.pop();
    }
  }

  int top()
  {
    if (!s1.empty())
    {
      return s1.top();
    }
    return -1;
  }
};

int main()
{
  MyQueue q;
  q.push(10);
  q.push(20);
  q.push(30);

  cout << "top element is: " << q.top() << endl;

  q.pop();

  cout << "top element after popping: " << q.top() << endl;

  return 0;
}
