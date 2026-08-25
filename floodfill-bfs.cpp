#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color) {
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int r = image.size();
        int c = image[0].size();
        int oldColor = image[sr][sc];
        queue<vector<int>> q;
        q.push({sr, sc});
        if (oldColor == color)
            return image;
        image[sr][sc] = color;
        while (!q.empty()) {
            vector<int> pos = q.front();
            q.pop();
            for (auto &d : dirs) {
                int nr = pos[0] + d[0];
                int nc = pos[1] + d[1];
                if (nr >= 0 && nr < r && nc >= 0 && nc < c && image[nr][nc] == oldColor) {
                    q.push({nr, nc});
                    image[nr][nc] = color;
                }
            }
        }
        return image;
    }
};