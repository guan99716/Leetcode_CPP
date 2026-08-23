#include <vector>
using namespace std;
class Solution {
private:
    int r, c, oldColor;
    void dfs(vector<vector<int>> &image, int sr, int sc, int color) {
        if (sr < 0 || sr >= r || sc < 0 || sc >= c)
            return;
        if (image[sr][sc] != oldColor)
            return;

        // oldColor != color and image[sr][sc] == oldColor
        image[sr][sc] = color;
        dfs(image, sr - 1, sc, color);
        dfs(image, sr, sc - 1, color);
        dfs(image, sr + 1, sc, color);
        dfs(image, sr, sc + 1, color);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                  int color) {
        r = image.size();
        c = image[0].size();
        oldColor = image[sr][sc];
        if (image[sr][sc] != color)
            dfs(image, sr, sc, color);
        return image;
    }
};