#include <set>
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
    void dfs(TreeNode *node, set<int> &s) {
        if (!node)
            return;
        s.insert(node->val);
        dfs(node->left, s);
        dfs(node->right, s);
    }

public:
    int findSecondMinimumValue(TreeNode *root) {
        set<int> s;
        dfs(root, s);
        if (s.size() >= 2)
            return *next(s.begin());
        return -1;
    }
};