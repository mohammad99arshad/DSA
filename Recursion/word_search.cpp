#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> direction{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool find(vector<vector<char>> &board, int i, int j, int ind, string &word, int m, int n)
{
    if (ind == word.size())
        return true;
    if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '#' || board[i][j] != word[ind])
        return false;

    char temp = board[i][j];
    board[i][j] = '#'; // mark visited

    for (auto &dir : direction)
    {
        int new_i = i + dir[0];
        int new_j = j + dir[1];

        if (find(board, new_i, new_j, ind + 1, word, m, n))
            return true;
    }

    board[i][j] = temp; // backtrack
    return false;
}

bool exist(vector<vector<char>> &board, string word)
{
    int m = board.size();
    int n = board[0].size();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == word[0] && find(board, i, j, 0, word, m, n))
            {
                return true;
            }
        }
    }
    return false;
}

int main(){
    string word = "ABCCED";
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    if(exist(board, word)){
        cout<<"TRUE";
    }else{
        cout<<"FALSE";
    }

    return 0;
}