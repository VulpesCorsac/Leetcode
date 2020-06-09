static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return ans-1;
    }

    int depth(TreeNode* node) {
        if (!node) {
            return 0;
        }

        auto l = depth(node->left);
        auto r = depth(node->right);

        ans = max(ans, l + r + 1);

        return max(l, r) + 1;
    }

    int ans = 1;
};