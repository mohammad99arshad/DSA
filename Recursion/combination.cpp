#include <bits/stdc++.h>
using namespace std;

void comboSum(int pos, vector<int> &nums, vector<int> &sub, vector<vector<int>> &res, int k)
{
    if (k < 0)
        return;
    if (k == 0)
    {
        res.push_back(sub);
        return;
    }
    for (int i = pos; i < nums.size(); i++)
    {
        if (i > pos && nums[i] == nums[i - 1])
            continue;
        sub.push_back(nums[i]);
        comboSum(i + 1, nums, sub, res, k - nums[i]);
        sub.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<int> sub;
    vector<vector<int>> res;
    sort(candidates.begin(), candidates.end());
    comboSum(0, candidates, sub, res, target);
    return res;
}

int main(){
    vector<int>num = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>>res = combinationSum2(num, target);
    for (const auto& combination : res) {
        for (int val : combination) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}