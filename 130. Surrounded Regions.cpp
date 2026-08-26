#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        // step1: 把邊界上的"O"做BFS，改成"S"
        int rows = board.size();
        int cols = board[0].size();
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if ((i == 0 || i == rows - 1 || j == 0 || j == cols - 1) && board[i][j] == 'O' ) {
                    // BFS on {i, j}
                    q.push({i, j});
                    board[i][j] = 'S';
                    while (!q.empty()) {
                        pair<int,int> pos = q.front();
                        q.pop();
                        for (auto &d : dirs) {
                            int nr = pos.first + d[0];
                            int nc = pos.second + d[1];
                            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && board[nr][nc] == 'O') {
                                board[nr][nc] = 'S';
                                q.push({nr, nc});
                            }
                        }
                    }
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
// 先沿著邊界找 "O", 再用BFS，把和邊界相連的都改成"S"
// 接著把 "O" 都改成 "X", 把 "S" 改回 "O"