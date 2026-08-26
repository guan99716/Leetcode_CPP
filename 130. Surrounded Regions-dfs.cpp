#include <queue>
#include <vector>
using namespace std;

class Solution {
private:
    void dfs(vector<vector<char>>& board, int rows, int cols, int i, int j) {
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        if (i < 0 || i >= rows || j < 0 || j >= cols || board[i][j] != 'O')
            return;
        board[i][j] = 'S';
        for (auto& d : dirs)
            dfs(board, rows, cols, i + d[0], j + d[1]);
    }

public:
    void solve(vector<vector<char>>& board) {
        // step1: 把邊界上的"O"做BFS，改成"S"
        int rows = board.size();
        int cols = board[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if ((i == 0 || i == rows - 1 || j == 0 || j == cols - 1) &&
                    board[i][j] == 'O') {
                    // DFS on {i, j}
                    dfs(board, rows, cols, i, j);
                }
            }
        }
        // step2: 把 "O" 都改成 "X", 把 "S" 改回 "O"
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'S')
                    board[i][j] = 'O';
            }
        }
    }
};