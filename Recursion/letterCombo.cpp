#include <bits/stdc++.h>
using namespace std;

void backtrack(int index, string path, string &digits, vector<string> &res, unordered_map<char, string> &phone)
{
    if (index == digits.size())
    {
        res.push_back(path);
        return;
    }
    for (char ch : phone[digits[index]])
    {
        backtrack(index + 1, path + ch, digits, res, phone);
    }
}

vector<string> letterCombinations(string digits)
{
    if (digits.empty())
        return {};

    unordered_map<char, string> phone = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

    vector<string> res;
    backtrack(0, "", digits, res, phone);
    return res;
}

int main()
{
    string s = "23";
    vector<string>res = letterCombinations(s);
    for(string ss : res){
        cout<<ss<<endl;
    }
    return 0;
}