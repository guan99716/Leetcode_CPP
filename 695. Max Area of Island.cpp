#include <vector>
using namespace std;

class Solution {
private:
    int r, c, maxArea = 0;
    int dfs(vector<vector<int>> &grid, int i, int j, int area) {
        if (i < 0 || i >= r || j < 0 || j >= c || grid[i][j] == 0)
            return area;
        grid[i][j] = '0';
        area++;
        dfs(grid, i - 1, j, area);
        dfs(grid, i, j - 1, area);
        dfs(grid, i + 1, j, area);
        dfs(grid, i, j + 1, area);
        return area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        r = grid.size();
        c = grid[0].size();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                maxArea = max(maxArea, dfs(grid, i, j, 0));
            }
        }
        return maxArea;
    }
};