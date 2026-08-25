#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
private:
    int bfs(TreeNode *root) {
        if (!root)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        int depth = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *node = q.front();
                q.pop();
                // if node is the first leaf, then return depth
                if (!node->left && !node->right)
                    return depth;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            depth++;
        }
        return 0;
    }

public:
    int minDepth(TreeNode *root) {
        if (!root)
            return 0;
        return bfs(root);
    }
};