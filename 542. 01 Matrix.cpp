#include <climits>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        // 1. initializtion
        vector<vector<int>> result = mat;
        queue<pair<int, int>> q;
        int rows = mat.size();
        int cols = mat[0].size();
        // 如果是0 就放入queue, 1就改成INT_MAX
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (result[i][j] == 0)
                    q.push({i, j});
                else
                    result[i][j] = INT_MAX;
            }
        }
        // 2. BFS
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (auto &d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];
                // if in bounds and mat(nr,nc) > mat(r,c)
                if (nr >= 0 && nr < r && nc >= 0 && nc < c && result[nr][nc] > result[r][c] + 1) {
                    result[nr][nc] = result[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        return result;
    }
};