#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const string &s, int left, int right)
{
    while (left < right)
    {
        if (s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}
void backtrack(int pos, string &path, vector<string> &sub, vector<vector<string>> &res)
{
    if (pos == path.size())
    {
        res.push_back(sub);
        return;
    }
    for (int i = pos; i < path.size(); i++)
    {
        if (isPalindrome(path, pos, i))
        {
            sub.push_back(path.substr(pos, i + 1 - pos));
            backtrack(i + 1, path, sub, res);
            sub.pop_back();
        }
    }
}
vector<vector<string>> partition(string s)
{
    vector<vector<string>> res;
    vector<string> sub;
    backtrack(0, s, sub, res);
    return res;
}
int main(){
    string s = "aab";
    vector<vector<string>>res = partition(s);
    for(const auto& dd : res){
        cout<<"[";
        for(string ss : dd){
            cout<<"[";
            cout<<ss;
            cout<<"]";
        }
        cout<<"]";
    }
    return 0;
}