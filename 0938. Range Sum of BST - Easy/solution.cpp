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
    int rangeSumBST(TreeNode* root, int L, int R) {
        int result = 0;

        if (!root) {
            result = 0;
        } else {
            if (root->val >= L && root->val <= R) {
                result += root->val;
            }

            if (root->val >= L && root->left) {
                result += rangeSumBST(root->left, L, R);
            }
            if (root->val <= R && root->right) {
                result += rangeSumBST(root->right, L, R);
            }
        }

        return result;
    }
};