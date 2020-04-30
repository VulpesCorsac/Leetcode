/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
    int result = INT_MIN;
    
    int maxPathSum(TreeNode* root) {
        maxPathRoot(root);
        
        return result;
    }
    
    int maxPathRoot(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        int l_val = max(0, maxPathRoot(root->left));
        int r_val = max(0, maxPathRoot(root->right));
        result = max(result, root->val + l_val + r_val);
        return root->val + max(l_val, r_val);
    }
};