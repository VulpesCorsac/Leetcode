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
    bool isUnivalTree(TreeNode* root) {
        if (!root) {
            return true;
        }
        
        if (root->left) {
            if (root->val != root->left->val) {
                return false;
            }
        }
        if (root->right) {
            if (root->val != root->right->val) {
                return false;
            }
        }
    
        return isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};