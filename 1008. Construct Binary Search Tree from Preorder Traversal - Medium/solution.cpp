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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return tree(preorder, 0, preorder.size()-1);
    }

    TreeNode* tree(vector<int>& preorder, size_t l, size_t r) {
        if (l > r)
            return nullptr;

        auto root = new TreeNode(preorder[l]);

        if (l == r)
            return root;

        auto mid = l+1;
        while (mid <= r && preorder[mid] < preorder[l])
            ++mid;

        root->left  = tree(preorder, l+1, mid-1);
        root->right = tree(preorder, mid, r);

        return root;
    }
};