
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
    void dfs(TreeNode *node, TreeNode *&curr) {
        if (!node)
            return;
        dfs(node->left, curr);
        curr->right = new TreeNode(node->val);
        curr = curr->right;
        dfs(node->right, curr);
    }

public:
    TreeNode *increasingBST(TreeNode *root) {
        TreeNode *dummy = new TreeNode(0);
        TreeNode *curr = dummy;
        dfs(root, curr);
        return dummy->right;
    }
};
