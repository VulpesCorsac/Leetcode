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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_idx[inorder[i]] = i;
        }

        return helper(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }

protected:
    TreeNode* helper(vector<int>& preorder, int p_from, int p_to, vector<int>& inorder, int i_from, int i_to) {
        if (p_from >= p_to || i_from >= i_to) {
            return nullptr;
        }

        // tree:        4 2 6  1  3 5 7
        // preorder: 4 [3 1 2]   [7 5 6]
        // inorder:    [1 2 3] 4 [5 6 7]

        int val = preorder[p_from];
        int pos = inorder_idx[val];

        int left_size = pos - i_from;

        return new TreeNode(val,
                            helper(preorder, p_from+1          , p_from+1+left_size, inorder, i_from, pos ),
                            helper(preorder, p_from+1+left_size, p_to              , inorder, pos+1 , i_to)
                           );
    }

    unordered_map < int , int > inorder_idx;
};