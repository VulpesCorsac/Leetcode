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
    bool isValidBST(TreeNode* root) {
        return checkBST(root, static_cast<long long>(INT_MIN)-1, static_cast<long long>(INT_MAX)+1);
    }
    
    bool checkBST(TreeNode* root, long long lowerLimit, long long upperLimit) {
        if (!root) {
            return true;
        }
        
        if (static_cast<long long>(root->val) <= lowerLimit ||
            static_cast<long long>(root->val) >= upperLimit) {
            return false;
        }
        
        return checkBST(root->left, lowerLimit, static_cast<long long>(root->val)) &&
               checkBST(root->right, static_cast<long long>(root->val), upperLimit);
        
    }
};