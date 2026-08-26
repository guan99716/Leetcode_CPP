#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>> &grid) {
        // 1: fresh, 2:rotten
        // step1: traverse grid, freshCount++ if 1 and push into queue if 2
        int freshCount = 0;
        int minutes = 0;
        queue<vector<int>> q;
        int r = grid.size();
        int c = grid[0].size();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1)
                    freshCount++;
                else if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        // step 2
        // stop condition： queue is empty or there is no fresh orange
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty() && freshCount > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                vector<int> pos = q.front(); // {pos[0], pos[1]}
                q.pop();
                // 找到pos上下左右的格子，如果是1，就改成2，並放入queue中，freshCount--
                for (auto &d : dirs) {
                    int nr = pos[0] + d[0];
                    int nc = pos[1] + d[1];
                    // 如果grid[x][y]在範圍內且為1 
                    if (nr >= 0 && nr < r && nc >= 0 && nc < c && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        freshCount--;
                        q.push({nr, nc});
                    }
                }  
            }
            minutes++;
        }
        if (freshCount > 0)
            return -1;
        return minutes;
    }
};

// 第一步：掃描整個網格
// 遍歷每個格子，做兩件事：碰到 2 就放進 queue，碰到 1 就用一個計數器記錄新鮮橘子的數量。

// 第二步：分層 BFS
// 跟你之前做的一模一樣，用 size 的 for 迴圈控制每一層。每一層處理完，時間加 1。擴散的時候，碰到 1 就把它改成 2，放進 queue，新鮮橘子計數器減 1。

// 第三步：看結果
// BFS 結束後，如果新鮮橘子計數器還不是 0，代表有橘子永遠腐爛不到，回傳 -1。否則回傳時間。
