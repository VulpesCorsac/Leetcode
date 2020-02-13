/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (!root) {
            return root;
        }
        
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        
        if (!root->left && !root->right && !root->val) {
            delete root;
            return nullptr;
        }
        
        return root;
    }
};