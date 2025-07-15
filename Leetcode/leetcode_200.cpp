#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0' || visited[i][j]) {
            return;
        }

        visited[i][j] = true;

        // Explore all 4 directions
        dfs(grid, visited, i + 1, j, m, n);  // Down
        dfs(grid, visited, i - 1, j, m, n);  // Up
        dfs(grid, visited, i, j + 1, m, n);  // Right
        dfs(grid, visited, i, j - 1, m, n);  // Left
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) return 0; // Edge case: Empty grid
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int islands = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    islands++;
                    dfs(grid, visited, i, j, m, n);
                }
            }
        }

        return islands;
    }
};

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    Solution sol;
    cout << "Number of Islands: " << sol.numIslands(grid) << endl;

    return 0;
}
