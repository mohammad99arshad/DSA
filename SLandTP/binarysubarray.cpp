#include <bits/stdc++.h>
using namespace std;

int countAtMost(vector<int> &nums, int goal)
{
    int l = 0, r = 0, count = 0, sum = 0;
    for (r = 0; r < nums.size(); ++r)
    {
        sum += nums[r];
        while (sum > goal && l <= r)
        {
            sum -= nums[l++];
        }
        count += (r - l + 1);
    }
    return count;
}

int numSubarraysWithSum(vector<int> &nums, int goal)
{
    if (goal < 0)
        return 0; // Important edge case
    return countAtMost(nums, goal) - countAtMost(nums, goal - 1);
}
int main()
{
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;
    int result = numSubarraysWithSum(nums, goal);
    cout << result << endl;
    return 0;
}
