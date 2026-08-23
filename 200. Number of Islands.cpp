#include <vector>
using namespace std;
class Solution {
private:
    int count = 0;
    int r, c;
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= r || j < 0 || j >= c || grid[i][j] == '0')
            return;
        grid[i][j] = 0;
        dfs(grid, i - 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i + 1, j);
        dfs(grid, i, j + 1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        r = grid.size();
        c = grid[0].size();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};