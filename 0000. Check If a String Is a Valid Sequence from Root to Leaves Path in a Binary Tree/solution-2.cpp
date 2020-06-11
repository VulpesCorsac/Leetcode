static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
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
class Solution {
public:
    bool isValidSequence(TreeNode* root, vector < int >& arr, int pos = 0) {
        if (!root || root->val != arr[pos]) {
            return false;
        }

        if (pos+1 == arr.size()) {
            return !root->left && !root->right;
        }

        return isValidSequence(root->left, arr, pos+1) || isValidSequence(root->right, arr, pos+1);
    }
};