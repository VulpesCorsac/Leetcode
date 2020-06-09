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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        find(root, p, q);

        return ans;
    }

private:
    int find(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return 0;
        }

        auto left  = find(root->left , p, q);
        auto right = find(root->right, p, q);
        auto self  = (root == p || root == q) ? 1 : 0;

        if (left + right + self >= 2) {
            ans = root;
        }

        return (left + right + self) ? 1 : 0;
    }

    TreeNode* ans = nullptr;
};