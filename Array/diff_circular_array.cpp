#include <bits/stdc++.h>
using namespace std;

int maxAdjacentDistance(vector<int> &nums)
{
  if (nums.size() < 2)
  {
    return 0;
  }
  int maxDiff = 0;
  for (int i = 1; i < nums.size(); i++)
  {
    int currDiff = abs(nums[i] - nums[i - 1]);
    if (currDiff > maxDiff)
    {
      maxDiff = max(maxDiff, currDiff);
    }
    int cirDiff = abs(nums[0] - nums[nums.size() - 1]);
    maxDiff = max(maxDiff, cirDiff);
  }
  return maxDiff;
}

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  cout << maxAdjacentDistance(arr) << endl;
  return 0;
}