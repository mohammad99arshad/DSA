#include <bits/stdc++.h>
using namespace std;

int priority(char op)
{
  if (op == '+' || op == '-')
    return 1;
  if (op == '*' || op == '/')
    return 2;
  return 0;
}

string reverse(string s)
{
  stack<char> st;
  for (char c : s)
  {
    if (c == '(')
      st.push(')');
    else if (c == ')')
      st.push('(');
    else
      st.push(c);
  }
  string reversed = "";
  while (!st.empty())
  {
    reversed += st.top();
    st.pop();
  }
  return reversed;
}

string infix2prefix(string s)
{
  s = reverse(s);
  int i = 0;
  string ans = "";
  stack<char> st;
  int n = s.size();

  while (i < n)
  {
    if ((s[i] >= 'A' && s[i] <= 'Z') ||
        (s[i] >= 'a' && s[i] <= 'z') ||
        (s[i] >= '0' && s[i] <= '9'))
    {
      ans += s[i];
    }
    else if (s[i] == '(')
    {
      st.push(s[i]);
    }
    else if (s[i] == ')')
    {
      while (!st.empty() && st.top() != '(')
      {
        ans += st.top();
        st.pop();
      }
      if (!st.empty())
        st.pop();
    }
    else
    {
      while (!st.empty() && priority(s[i]) <= priority(st.top()))
      {
        ans += st.top();
        st.pop();
      }
      st.push(s[i]);
    }
    i++;
  }

  while (!st.empty())
  {
    ans += st.top();
    st.pop();
  }
  ans = reverse(ans);
  return ans;
}

int main()
{
  string expr = "a+(b*c)";
  cout << "Prefix: " << infix2prefix(expr) << endl;
  return 0;
}
