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
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) {
            return {};
        }
        
        vector < int > ans;
        stack < TreeNode* > nodes;
        TreeNode* last = nullptr;
        
        while (root || !nodes.empty()) {
            if (root) {
                nodes.push(root);
                root = root->left;
            } else {
                auto node = nodes.top();
                if (node->right && last != node->right) {
                    root = node->right;
                } else {
                    ans.push_back(node->val);
                    last = node;
                    nodes.pop();
                }
            }
        }
        
        return ans;
    }
};