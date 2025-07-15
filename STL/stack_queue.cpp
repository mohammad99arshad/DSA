#include <bits/stdc++.h>
using namespace std;

class MyStack
{
  queue<int> q;

  void pushh(int x)
  {
    int s = q.size();
    q.push(x);

    // for (int i = 1; i < s; i++)
    while (s--)
    {
      q.push(q.front());
      q.pop();
    }
  }
  void pop(int x)
  {
    if (!q.empty())
      q.pop();
  }
  int top()
  {
    if (!q.empty())
      return q.front();
  }
};

int main()
{
  stack<int> st;
  st.push(10);
  st.push(20);
  st.push(30);
  cout << "top element is: " << st.top() << endl;
  st.pop();
  cout << "top element after popping: " << st.top();
  return 0;
}