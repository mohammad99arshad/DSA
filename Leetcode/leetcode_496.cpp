#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
  {
    vector<int> res;

    for (int i = 0; i < nums1.size(); i++)
    {
      int found = -1;

      for (int j = 0; j < nums2.size(); j++)
      {
        if (nums2[j] == nums1[i])
        {
          for (int k = j + 1; k < nums2.size(); k++)
          {
            if (nums2[k] > nums1[i])
            {
              found = nums2[k];
              break;
            }
          }
          break;
        }
      }

      res.push_back(found);
    }

    return res;
  }
};

int main()
{
  Solution s;
  vector<int> arr1 = {4, 1, 2};
  vector<int> arr2 = {1, 3, 4, 2};

  vector<int> result = s.nextGreaterElement(arr1, arr2);

  for (int val : result)
  {
    cout << val << " ";
  }

  return 0;
}
