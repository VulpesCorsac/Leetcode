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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_idx[inorder[i]] = i;
        }
        
        return helper(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
    
protected:
    TreeNode* helper(vector<int>& inorder, int i_from, int i_to, vector<int>& postorder, int p_from, int p_to) {
        if (i_from >= i_to || p_from >= p_to) {
            return nullptr;
        }
        
        // tree:       4 2 6  1  3 5 7
        // inorder:   [1 2 3] 4 [5 6 7]
        // postorder: [1 3 2]   [5 7 6] 4 
        
        int val = postorder[p_to-1];
        int pos = inorder_idx[val];
        
        int left_size = pos - i_from;
        
        return new TreeNode(val,
                            helper(inorder, i_from, pos , postorder, p_from          , p_from+left_size),
                            helper(inorder, pos+1 , i_to, postorder, p_from+left_size, p_to-1          )
                           );
    }
    
    unordered_map < int , int > inorder_idx;
};