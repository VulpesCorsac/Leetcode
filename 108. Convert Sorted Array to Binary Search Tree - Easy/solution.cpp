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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }

private:
    TreeNode* helper(vector<int>& nums, int l, int r) {
        if (r < l) {
            return nullptr;
        } else if (l == r) {
            return new TreeNode(nums[l]);
        } else {
            int m = l + (r - l) / 2;
            
            auto root = new TreeNode(nums[m]);
            root->left  = helper(nums, l, m-1);
            root->right = helper(nums, m+1, r);
            
            return root;
        }
    }    
};