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
    int maxDepth(TreeNode* root) {
        return func(root, 1);
    }

    int func(TreeNode* root, int depth) {
        if (!root) {
            return depth-1;
        }

        return max(func(root->left, depth+1),
                   func(root->right, depth+1));
    }
};