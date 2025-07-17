#include <bits/stdc++.h>
using namespace std;

int sumOfSubArray(vector<int> &arr)
{
  int n = arr.size();
  stack<pair<int, int>> st;
  long long res = 0, dot = 0;
  long long mod = 1e9 + 7;

  for (int i = 0; i < n; i++)
  {
    int count = 1;
    while (!st.empty() && st.top().first >= arr[i])
    {
      count += st.top().second;
      dot -= (long long)st.top().first * st.top().second;
      st.pop();
    }
    dot += (long long)arr[i] * count;
    st.push({arr[i], count});
    res = (res + dot) % mod;
  }
  return res;
}

int main()
{
  vector<int> arr = {3, 1, 2, 4};
  int result = sumOfSubArray(arr);
  cout << "Sum of Minimum of Subarray: " << result;
  return 0;
}