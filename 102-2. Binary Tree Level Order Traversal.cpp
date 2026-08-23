#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 不分層
class Solution {
public:
    void levelOrder(TreeNode *root, vector<int> &res) {
        if (!root)
            return;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            res.push_back(node->val);
            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);
        }
    }
};