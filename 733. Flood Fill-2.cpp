#include <vector>
using namespace std;
class Solution {
private:
    int r, c;
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(vector<vector<int>> &image, int sr, int sc, int oldColor,
             int color) {
        if (sr < 0 || sr >= r || sc < 0 || sc >= c || image[sr][sc] != oldColor)
            return;
        image[sr][sc] = color;
        for (auto &d : dirs) {
            dfs(image, sr + d[0], sc + d[1], oldColor, color);
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                  int color) {
        r = image.size();
        c = image[0].size();
        int oldColor = image[sr][sc];
        if (oldColor != color)
            dfs(image, sr, sc, oldColor, color);
        return image;
    }
};