#include <bits/stdc++.h>
using namespace std;

vector<int> MedianArray(vector<int> ar1, vector<int> ar2)
{
  vector<int> st;

  for (int i = 0; i < ar1.size(); i++)
  {
    int inserted = 0;
    for (int j = 0; j < st.size(); j++)
    {
      if (ar1[i] < st[j])
      {
        st.insert(st.begin() + j, ar1[i]);
        inserted = 1;
        break;
      }
    }
    if (!inserted)
      st.push_back(ar1[i]);
  }

  for (int i = 0; i < ar2.size(); i++)
  {
    int inserted = 0;
    for (int j = 0; j < st.size(); j++)
    {
      if (ar2[i] < st[j])
      {
        st.insert(st.begin() + j, ar2[i]);
        inserted = 1;
        break;
      }
    }
    if (!inserted)
      st.push_back(ar2[i]);
  }

  vector<int> result;
  int n = st.size();
  if (n % 2 == 1)
  {
    result.push_back(st[n / 2]);
  }
  else
  {
    result.push_back(st[n / 2 - 1]);
    result.push_back(st[n / 2]);
  }
  return result;
}

int main()
{
  vector<int> ar1 = {1, 3, 5};
  vector<int> ar2 = {2, 4, 6};
  vector<int> median = MedianArray(ar1, ar2);
  for (int val : median)
  {
    cout << val << " ";
  }
  cout << endl;
  return 0;
}
