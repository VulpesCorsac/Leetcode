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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) {
            return nullptr;
        }

        int t1_val = t1 ? t1->val : 0;
        int t2_val = t2 ? t2->val : 0;

        auto result = new TreeNode(t1_val + t2_val);

        result->left = mergeTrees(t1 ? t1->left : nullptr,
                                  t2 ? t2->left : nullptr);
        result->right = mergeTrees(t1 ? t1->right : nullptr,
                                   t2 ? t2->right : nullptr);

        return result;
    }
};