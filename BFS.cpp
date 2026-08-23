#include <iostream>
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

int main() {
    queue<TreeNode *> q;
    TreeNode * root;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            TreeNode *node = q.front();
            q.pop();

            // 處理當前節點
            cout << node->val << endl;

            // 把下一層放進去
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }
}