#include <bits/stdc++.h>
using namespace std;

int atMostSubarray(vector<int> &nums, int k)
{
    int l = 0, r = 0, count = 0, sum = 0;
    while (r < nums.size())
    {
        sum += (nums[r] % 2 == 1);
        while (sum > k)
        {
            sum -= (nums[l] % 2 == 1);
            l++;
        }
        count += (r - l + 1);
        r++;
    }
    return count;
}

int numberOfSubarrays(vector<int> &nums, int k)
{
    return atMostSubarray(nums, k) - atMostSubarray(nums, k - 1);
}

int main()
{
    vector<int> arr = {1, 1, 2, 1, 1};
    int k = 3;
    int result = numberOfSubarrays(arr, k);
    cout << result << endl;
    return 0;
}
