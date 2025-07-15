#include <bits/stdc++.h>
using namespace std;

class MinStack
{
  stack<pair<int, int>> st;

public:
  void push(int val)
  {
    if (st.empty())
    {
      st.push({val, val});
    }
    else
    {
      st.push({val, min(val, st.top().second)});
    }
  }

  void pop()
  {
    if (!st.empty())
      st.pop();
  }

  int top()
  {
    return st.top().first;
  }

  int getMin()
  {
    return st.top().second;
  }
};

int main()
{
  MinStack st;
  vector<int> ar = {-2, 0, -3};
  for (int val : ar)
  {
    st.push(val);
  }
  st.push(-4);
  cout << "top element is: " << st.top();
  st.pop();
  cout << "top element is: " << st.top();
  cout << "minimum element is: " << st.getMin();
}